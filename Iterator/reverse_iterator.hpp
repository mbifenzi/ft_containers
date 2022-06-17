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
            explicit reverse_iterator (iterator_type it):_it(it){}
            reverse_iterator(const reverse_iterator & to_copy) : _it(to_copy._it){}
            iterator_type base() const { return _it; }
            reverse_iterator &operator=(const reverse_iterator &it) { _it = it._it; return *this; }
            
            reverse_iterator &operator++() { _it--; return *this; }
            reverse_iterator &operator--() { _it++; return *this; }
            reverse_iterator &operator+=(difference_type n) { _it -= n; return *this; }
            reverse_iterator &operator-=(difference_type n) { _it += n; return *this; }
            reverse_iterator operator++(int) { reverse_iterator tmp(*this); _it--; return tmp; }
            reverse_iterator operator--(int) { reverse_iterator tmp(*this); _it++; return tmp; }
            reverse_iterator operator+(difference_type n) { reverse_iterator tmp(*this); tmp._it -= n; return tmp; }
            reverse_iterator operator-(difference_type n) { reverse_iterator tmp(*this); tmp._it += n; return tmp; }
            difference_type operator-(reverse_iterator const &it) { return it._it - _it; }
            pointer operator->() { return &*_it; }
            reference operator*() { return *(_it - 1); }
            reference operator[](difference_type n) { return _it[-n]; }
            bool operator==(reverse_iterator const &it) { return _it == it._it; }
            bool operator!=(reverse_iterator const &it) { return _it != it._it; }
            bool operator<(reverse_iterator const &it) { return _it > it._it; }
            bool operator>(reverse_iterator const &it) { return _it < it._it; }
            bool operator<=(reverse_iterator const &it) { return _it >= it._it; }
            bool operator>=(reverse_iterator const &it) { return _it <= it._it; }


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



    

}