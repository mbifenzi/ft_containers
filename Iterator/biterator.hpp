#pragma once

#include "iterator_traits.hpp"
#include "../Containers/Map/rbt.hpp"

namespace ft
{
    template <class Node, class T, class value_compare, class Alloc >
    class biterator
    {
		public:
			typedef T											value_type;
			typedef ptrdiff_t									difference_type;
			typedef T*											pointer;
			typedef T&											reference;
			typedef typename std::bidirectional_iterator_tag	iterator_category;
			typedef Biterator<const iterator_type, value_type, value_compare, Alloc > const_iterator;
			typedef Node<T*>	node_ptr;
		private:
			node_ptr	_node;
			node_ptr	_root;
		public:
		node_ptr max(node_ptr x)
		{
			node_ptr tmp = x;
			while (tmp->right != 0)
				tmp = tmp->right;
			return tmp;
		}

		node_ptr min(node_ptr x)
		{
			node_ptr tmp = x;
			while (tmp->right != 0)
				tmp = tmp->right;
			return tmp;
		}



			
    };
}