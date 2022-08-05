#pragma once 

#include "iterator_traits.hpp"

namespace ft
{
    template <typename Iterator>
    class reverse_iterator
    {
        protected :
            Iterator _it;
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_type::value_type value_type;
            typedef typename iterator_type::difference_type difference_type;
            typedef typename iterator_type::pointer pointer;
            typedef typename iterator_type::reference reference;
            typedef typename iterator_type::iterator_category iterator_category;
            reverse_iterator(){};
            explicit reverse_iterator (iterator_type it):_it(--it){}
            // reverse_iterator(const reverse_iterator & rhs) : _it(rhs._it){}
            reverse_iterator(const reverse_iterator<iterator_type>& _it){ this->operator=(_it);};

            iterator_type base() const { return _it; }

            template <class Iter>
            reverse_iterator &operator=(const reverse_iterator<Iter> &it) { _it = it.base(); return *this; }            
            reverse_iterator &operator++() { _it--; return *this; }
            reverse_iterator &operator--() { _it++; return *this; }
            reverse_iterator &operator+=(difference_type n) { _it -= n; return *this; }
            reverse_iterator &operator-=(difference_type n) { _it += n; return *this; }
            reverse_iterator operator++(int) { reverse_iterator tmp(*this); _it--; return tmp; }
            reverse_iterator operator--(int) { reverse_iterator tmp(*this); _it++; return tmp; }


			reverse_iterator operator+ (difference_type n) const
			{
				reverse_iterator tmp(_it - n);
				return (tmp);
			}
            			reverse_iterator operator- (difference_type n) const
			{
				reverse_iterator tmp(_it + n);
				return (tmp);
			}
            pointer operator->() { 
                iterator_type tmp(_it);
                --tmp;
                return tmp.operator->(); 
            }
            reference operator*() { return *(_it); }
            reference operator[](difference_type n) { return _it[-n -1]; }
            bool operator==(reverse_iterator const &it) { return _it == it._it; }
            bool operator!=(reverse_iterator const &it) { return _it != it._it; }
            bool operator<(reverse_iterator const &it) { return _it > it._it; }
            bool operator>(reverse_iterator const &it) { return _it < it._it; }
            bool operator<=(reverse_iterator const &it) { return _it >= it._it; }
            bool operator>=(reverse_iterator const &it) { return _it <= it._it; }

            operator	reverse_iterator<const iterator_type>() const{
			    return reverse_iterator<const iterator_type>(_it);
	        }

    };
    template <typename Iterator>
    bool operator==(reverse_iterator<Iterator> const &it1, reverse_iterator<Iterator> const &it2)
    {
        return it1.base() == it2.base();
    }

    template <typename Iterator>
    bool operator!=(reverse_iterator<Iterator> const &it1, reverse_iterator<Iterator> const &it2)
    {
        return it1.base() != it2.base();
    }

    template <typename Iterator>
    bool operator<(reverse_iterator<Iterator> const &it1, reverse_iterator<Iterator> const &it2)
    {
        return it1.base() > it2.base();
    }

    template <typename Iterator>
    bool operator>(reverse_iterator<Iterator> const &it1, reverse_iterator<Iterator> const &it2)
    {
        return it1.base() < it2.base();
    }

    template <typename Iterator>
    bool operator<=(reverse_iterator<Iterator> const &it1, reverse_iterator<Iterator> const &it2)
    {
        return it1.base() >= it2.base();
    }

    template <typename Iterator>
    bool operator>=(reverse_iterator<Iterator> const &it1, reverse_iterator<Iterator> const &it2)
    {
        return it1.base() <= it2.base();
    }


    template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}
	//operator -
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}

    
    

}