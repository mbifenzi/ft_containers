#pragma once
#include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class iterator_op: public std::iterator<std::random_access_iterator_tag, T>
    {
        public:
			typedef typename iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename iterator<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename iterator<std::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename iterator<std::random_access_iterator_tag, T>::reference			reference;
			typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
	
			iterator_op() {};
			
			iterator_op(iterator_op const & to_copy)
            {
				_iterator = to_copy._iterator;
			};
			
			iterator_op(T * pointer){
				_iterator = pointer;
			}
    };
};