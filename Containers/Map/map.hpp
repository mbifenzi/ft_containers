#pragma once

#include <iostream>
#include <memory>
#include "rbt.hpp"
#include <utility>
#include <stdexcept>
#include <functional>
#include "../../Utilities/pair.hpp"
#include "../Vector/Vector.hpp"
// #include "../../Iterator/biterator.hpp"

namespace ft
{

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
	class map
	{
				
		public:
			class value_compare;
			typedef Key     													key_type;
			typedef T															mapped_type;
			typedef T&															mapped_type_referece;
			typedef Compare														key_compare;
			typedef Alloc 														allocator_type;
			typedef size_t 														size_type;																						
			typedef ft::pair<const key_type, mapped_type>						value_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::difference_type					difference_type;
			typedef Node<value_type>*											node_ptr;
			typedef typename ft::reverse_iterator<typename rbt<value_type, value_compare, Alloc>::iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<typename rbt<value_type, value_compare, Alloc>::const_iterator>	const_reverse_iterator;
			typedef typename rbt<value_type, value_compare, Alloc>::iterator											iterator;
			typedef typename rbt<value_type, value_compare, Alloc>::const_iterator										const_iterator;
			// typedef typename rbt<value_type, value_compare, Alloc>::node_type											node_type;
			protected:
				key_compare                             _comp;
				allocator_type                          _alloc;
				value_compare                           _value_comp;
				rbt<value_type, value_compare, Alloc>   _rbt;
			public:
			// map() : _rbt() { }
			explicit map(const key_compare &c = key_compare(), const Alloc &alloc = allocator_type()) : 
				_comp(c), _alloc(alloc), _value_comp(c), _rbt(_value_comp, _alloc ) { }

			map(const map &rhs) :_comp(rhs._comp) , _alloc(rhs._alloc),  _rbt(rhs._rbt) { }

			map &operator=(const map &rhs) { _rbt = rhs._rbt; _alloc = rhs._alloc; _comp = rhs._comp; return(*this); }
			
			template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type(),
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()):
                _comp(comp), _alloc(alloc), _rbt() {
                _rbt.set_compare_alloc(value_compare(comp), alloc);
                while (first != last){
                    _rbt.insert(*first);
                    first++;
                }
            };
			void clear() {_rbt.clear();};
			 ~map() { _rbt.clear();}
			mapped_type_referece operator[](const key_type &key)
			{
				return (_rbt.insert(ft::make_pair(key, mapped_type())).first)->second;
			}
			pair<iterator,bool> insert (const value_type& val)
			{
				return(_rbt.insert(val));
				// std::cout << "inserted " << val.first << " " << val.second << std::endl;
			};

			iterator insert (iterator position, const value_type& val) { 
				(void)position;
				return( _rbt.insert(val).first);
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last ) {
				// _rbt.insert(first, last);
				// loop through the range and insert each element
				// insert each element into the tree

				while (first != last) {
					_rbt.insert(*first);
					first++;
				}
			}
					iterator begin() { return(iterator(_rbt.min(), _rbt.root())); }
					const_iterator begin() const { return(const_iterator(_rbt.min(), _rbt.root())); }
					iterator end() { return(iterator(_rbt.max()->_Rchild, _rbt.root())); }
					const_iterator end() const { return(const_iterator(_rbt.max()->_Rchild, _rbt.root())); }
					reverse_iterator rbegin() { return reverse_iterator(end()); }
					const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
					reverse_iterator rend() { return reverse_iterator(begin()); }
					const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
					bool empty() const { return(_rbt.empty()); }
					size_type size() const { return(_rbt.size()); }
					size_type max_size() const { return(_rbt.max_size()); }
					key_compare key_comp() const { return(_comp); }
					value_compare value_comp() const { return(_value_comp); }
					allocator_type get_allocator() const { return(_alloc); }
					
					// mapped_type &at(const key_type &key)
					// {
					// 	iterator it = find(key);
					// 	if (it == end())
					// 		throw std::out_of_range("map::at");
					// 	return(it->second);
					// }
					// const mapped_type &at(const key_type &key) const
					// {
					// 	const_iterator it = find(key);
					// 	if (it == end())
					// 		throw std::out_of_range("map::at");
					// 	return(it->second);
					// }
					iterator find(const key_type &key) { return _rbt.find(ft::make_pair(key, mapped_type())); }
					const_iterator find(const key_type &key) const { return _rbt.find(ft::make_pair(key, mapped_type()));}


					size_type count(const key_type &key) const
					{
						return(find(key) == end() ? 0 : 1);
					}
					iterator lower_bound(const key_type &key)
					{
						iterator found = find(key);
						if (found != end())
							return found;
						return (_rbt.bound(ft::make_pair(key, mapped_type())));
					}

					const_iterator lower_bound(const key_type &key) const
					{
						const_iterator found = find(key);
						if (found != end())
							return found;
						return (_rbt.bound(ft::make_pair(key, mapped_type())));
					}

					iterator upper_bound(const key_type &key)
					{
						return (_rbt.bound(ft::make_pair(key, mapped_type())));
					}

					const_iterator upper_bound(const key_type &key) const
					{
						return (_rbt.bound(ft::make_pair(key, mapped_type())));
					}

					ft::pair<iterator, iterator> equal_range(const key_type &key)
					{
						iterator it1 = lower_bound(key);
						iterator it2 = upper_bound(key);
						return(ft::make_pair(it1, it2));
					}

					ft::pair<const_iterator, const_iterator> equal_range(const key_type &key) const
					{
						const_iterator it1 = lower_bound(key);
						const_iterator it2 = upper_bound(key);
						return(ft::make_pair(it1, it2));
					}

					void swap(map &other)
					{
						_rbt.swap(other._rbt);
						std::swap(_comp, other._comp);
						std::swap(_alloc, other._alloc);
					}

					void erase(iterator it) { _rbt.erase(*it); }

					size_type erase (const key_type& k) { return (_rbt.erase(ft::make_pair(k, mapped_type()))); };

					void erase (iterator first, iterator last)
					{
						ft::vector<key_type> tmp;
						for (; first != last; first++)
							tmp.push_back(first->first);
						for (size_type i = 0; i < tmp.size(); i++)
							_rbt.erase(ft::make_pair(tmp[i], mapped_type()));
					};

			node_ptr getNode()
			{
				return _rbt.getNode();
			}
	};


template <class Key, class T, class Compare, class Alloc>
bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
	return (!(lhs < rhs) && !(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}


template <class Key, class T, class Compare, class Alloc>
bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return !(lhs > rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
	return rhs < lhs;
}

template <class Key, class T, class Compare, class Alloc>
bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
	return !(lhs < rhs);
}

	template <class Key, class T, class Compare, class Alloc>
	class map<Key,T,Compare,Alloc>::value_compare : public std::binary_function<value_type, value_type, bool>
	{
		friend class map<Key,T,Compare,Alloc>;
		protected:
			Compare _comp;
		public:
			value_compare(const Compare &c) : _comp(c) { }
			value_compare(){};
			bool operator()(const value_type &lhs, const value_type &rhs) const
			{
				return(_comp(lhs.first, rhs.first));
			}
	};

}
