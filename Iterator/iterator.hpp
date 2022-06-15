#pragma once
#include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class iterator_op: public std::iterator<std::random_access_iterator_tag, T>
    {
		private:
			T *_ptr;
        public:
			typedef typename iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename iterator<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename iterator<std::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename iterator<std::random_access_iterator_tag, T>::reference			reference;
			typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
	
			iterator_op() {};
			
			iterator_op(iterator_op const & to_copy) { _ptr = to_copy._ptr; };
			iterator_op(T * pointer){ _ptr = pointer; };
			iterator_op &operator=(const iterator_op &it) { _ptr = it._ptr; return *this; };
			operator  iterator_op< const value_type>() const { return iterator_op< const value_type>(_ptr); };
			iterator_op &operator++() { _ptr++; return *this; };
			iterator_op &operator--() { _ptr--; return *this; };
			iterator_op &operator+=(difference_type n) { _ptr += n; return *this; };
			iterator_op &operator-=(difference_type n) { _ptr -= n; return *this; };
			iterator_op operator++(int) { iterator_op tmp(*this); _ptr++; return tmp; };
			iterator_op operator--(int) { iterator_op tmp(*this); _ptr--; return tmp; };
			iterator_op operator+(difference_type n) { iterator_op tmp(*this); tmp._ptr += n; return tmp; };
			iterator_op operator-(difference_type n) { iterator_op tmp(*this); tmp._ptr -= n; return tmp; };
			difference_type operator-(iterator_op const &it) { return _ptr - it._ptr; };
			pointer operator->() { return _ptr; };
			bool operator==(iterator_op const &it) { return _ptr == it._ptr; };
			bool operator!=(iterator_op const &it) { return _ptr != it._ptr; };
			bool operator<(iterator_op const &it) { return _ptr < it._ptr; };
			bool operator>(iterator_op const &it) { return _ptr > it._ptr; };
			bool operator<=(iterator_op const &it) { return _ptr <= it._ptr; };
			bool operator>=(iterator_op const &it) { return _ptr >= it._ptr; };
			reference operator[](difference_type n) { return _ptr[n]; };
			reference operator*() const { return *_ptr; };
			pointer operator&() const { return _ptr; };
    };
};