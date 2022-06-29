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
			biterator() : _node(NULL), _root(NULL) {};
			biterator(const biterator& rhs){*this = rhs;};
			biterator(node_ptr node, node_ptr root) : _node(node), _root(root) {};
			biterator& operator=(const biterator& rhs)
			{
				this->_node = rhs._node;
				this->_root = rhs._root;
				return(*this);
			}

			reference operator*() const
			{
				return(_node->_data);
			}

			pointer operator->() const
			{
				return(&(_node->_data));
			}

			biterator& operator++()
			{
				if (!_node && _root)
					_node = _root->_left;
				else if (_node->_right)
					_node = _node->_right;
				else
				{
					node_ptr parent = _node->_parent;
					while (parent && _node == parent->_right)
					{
						_node = parent;
						parent = parent->_parent;
					}
					_node = parent;
				}
			}

			biterator operator++(int)
			{
				biterator tmp = *this;
				++*this;
				return(tmp);
			}
			
			biterator& operator--()
			{
				if (_node->_Lchild != NULL)
				{
					_node = _node->_Lchild;
					while (_node->_Rchild != NULL)
						_node = _node->_Rchild;
				}
				else
				{
					while (_node->_Parent != NULL && _node->_Parent->_Lchild == _node)
						_node = _node->_Parent;
					_node = _node->_Parent;
				}
				return(*this);
			}

			biterator operator--(int)
			{
				biterator tmp = *this;
				--*this;
				return(tmp);
			}

			friend bool operator==(const biterator& rhs) const
			{
				return(_node == rhs._node);
			}

			friend bool operator!=(const biterator& rhs) const
			{
				return(_node != rhs._node);
			}



			virtual ~biterator(){};
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