#pragma once

#include "../Map/map.hpp"

namespace ft{

	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> > 
	class set {
		public:
			typedef size_t  size_type;
            typedef T       key_type;
			typedef T       value_type;
            typedef ft::pair<const key_type, value_type> value_type_pair;
			typedef Compare key_compare;
			typedef Compare value_compare;
			typedef Alloc   allocator_type;
        	typedef typename	allocator_type::pointer	pointer;
			typedef typename	allocator_type::const_pointer	const_pointer;
			typedef typename	allocator_type::reference	reference;
			typedef typename	allocator_type::const_reference const_reference;
			typedef typename    ft::rbt<value_type, value_compare, allocator_type>::iterator iterator;
        	typedef typename    ft::rbt<value_type, value_compare, allocator_type>::const_iterator const_iterator;
			typedef	            ft::reverse_iterator<iterator>	reverse_iterator;
			typedef	            ft::reverse_iterator<const_iterator>	const_reverse_iterator;
        	typedef typename    ft::iterator_traits<iterator>::difference_type  difference_type;
		protected:
			key_compare _comp;
            allocator_type _alloc;
            rbt<value_type, value_compare, allocator_type> _rbt;
		public:
			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_comp(comp) ,_alloc(alloc), _rbt() { _rbt.set_compare_alloc(comp, alloc);};
			template <class InputIterator>
            set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type(),
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()):
                _comp(comp), _alloc(alloc), _rbt() {
                _rbt.set_compare_alloc(comp, alloc);
                while (first != last){
                    _rbt.insert(*first);
                    first++;
                }
            };
			set (const set& x){*this = x;};

			// Destructor
			virtual ~set() {clear();};

            // Assing operator
            set& operator= (const set& x){
                _rbt = x._rbt;
                return (*this);
            };

			// Iterators
            iterator				begin() { return _rbt.begin(); }
		    const_iterator			begin() const { return _rbt.begin(); }
		    iterator				end() { return _rbt.end(); }
		    const_iterator			end() const { return _rbt.end(); }
		    reverse_iterator		rbegin() { return _rbt.rbegin(); }
		    const_reverse_iterator	rbegin() const { return _rbt.rbegin(); }
		    reverse_iterator		rend() { return _rbt.rend(); }
		    const_reverse_iterator	rend() const { return _rbt.rend(); }

			//Capacity
            size_type size() const{return _rbt.size() ;};
            bool empty() const{return _rbt.empty();};
            size_type max_size() const{return _rbt.max_size();};

			//Modifires
            pair<iterator,bool> insert (const value_type& val){
                return _rbt.insert(val);
            };
            iterator insert (iterator position, const value_type& val){
                (void)position;
                return _rbt.insert(val).first;
            };
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){
                while (first != last){
                    _rbt.insert(*first);
                    first++;
                }
            };
            void erase (iterator position){
                _rbt.erase(*position);
            };
            size_type erase (const value_type& k){
                return (_rbt.erase(k));
            };
            void erase (iterator first, iterator last){
                ft::vector<value_type> tmp;
                for (; first != last; first++)
                    tmp.push_back(*first);
                for (size_type i = 0; i < tmp.size(); i++)
                    _rbt.erase(tmp[i]);
            };
			void clear(){_rbt.clear();};
            void swap (set& x){
                _rbt.swap(x._rbt);
                std::swap(x._alloc, this->_alloc);
                std::swap(x._comp, this->_comp);
            };

			//Observers:
            key_compare key_comp() const{return _comp;};
            value_compare value_comp() const{return _comp;};

			//Operations:
            iterator find (const value_type& k) {
                return _rbt.find(k);
            };
			size_type count (const value_type& k) const{
                return (_rbt.find(k) == end()) ? 0 : 1;
            };
			iterator lower_bound (const value_type& k) 
            {
                iterator found = find(k);
                if (found != end())
                    return found;
                return (_rbt.bound(k));
            };
			iterator upper_bound (const value_type& k) const
            {
                return (_rbt.bound(k));
            };
			pair<iterator,iterator> equal_range (const value_type& k) 
            {
                return ft::make_pair(lower_bound(k), upper_bound(k));
            };

			// allocator getter
            allocator_type get_allocator() const { return _alloc; }
	};
	template <class T, class Compare, class Alloc>
    bool operator== ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
    {
    	if(lhs.size() == rhs.size())
    		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    	return false;
    }
    template < class T, class Compare, class Alloc>
    bool operator!= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
    {
    	return !(lhs == rhs);
    }
    template <class T, class Compare, class Alloc>
    bool operator<  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
    {
    	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <class T, class Compare, class Alloc>
    bool operator<= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
    {
    	return !(rhs < lhs);
    }
    template <class T, class Compare, class Alloc>
    bool operator>  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
    {
    	return (rhs < lhs);
    }
    template <class T, class Compare, class Alloc>
    bool operator>= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
    {
    	return !(lhs < rhs);
    }
    template <class T, class Compare, class Alloc>
    void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y)
    {
    	x.swap(y);
    }
}