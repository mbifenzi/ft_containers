#pragma once

#include "iterator_traits.hpp"
#include "../Containers/Map/rbt.hpp"


namespace ft
{
    template <class Node, class T>
    class biterator
    {
		
		public:
			typedef T											value_type;
			typedef ptrdiff_t									difference_type;
			typedef T*											pointer;
			typedef const T*									const_pointer;
			typedef T&											reference;
			typedef typename std::bidirectional_iterator_tag	iterator_category;
			typedef typename Node::pointer								node_ptr;
			// typedef typename Node::const_pointer						const_node_ptr;
		protected:
			node_ptr	_node;
			node_ptr	_root;
		public:
			biterator() : _node(NULL), _root(NULL) {};
			biterator(const biterator& rhs){*this = rhs;};
			biterator(node_ptr node, node_ptr root) : _node(node), _root(root) {};
			biterator& operator=( const biterator& rhs )
			{
				this->_node = rhs._node;
				this->_root = rhs._root;
				return(*this);
			}

			reference operator*() const
			{
				return *(_node->_data);
			}

			pointer operator->() 
			{
				return (_node->_data);
			}

			const_pointer operator->() const
			{
				return (_node->_data);
			}


			biterator& operator++()
			{
				if (!_node && _root)
					_node = _min(_root);
				else if (_node->_Rchild)
					_node = _min(_node->_Rchild);
				else
				{
					node_ptr parent = _node->_Parent;
					while (parent && _node == parent->_Rchild)
					{
						_node = parent;
						parent = parent->_Parent;
					}
					_node = parent;
				}
				return(*this);
			}

			biterator operator++(int)
			{
				biterator tmp = *this;
				++*this;
				return(tmp);
			}

			biterator& operator--()
			{
				if (!_node && _root)
					_node = _max(_root);
				else if (_node->_Lchild)
					_node = _max(_node->_Lchild);
				else
				{
					node_ptr parent = _node->_Parent;
					while (parent && _node == parent->_Lchild)
					{
						_node = parent;
						parent = parent->_Parent;
					}
					_node = parent;
				}
				return(*this);
			}

			biterator operator--(int)
			{
				biterator tmp = *this;
				--(*this);
				return(tmp);
			}

			node_ptr	base() const {	return(_node);	}

			node_ptr	root() const {	return(_root);	}

			friend bool	operator==(biterator const &lhs, biterator const &rhs)	{	return lhs._node == rhs._node;	}


			friend bool	operator!=(biterator const &lhs, biterator const &rhs)	{	return lhs._node != rhs._node;	}

			operator	biterator<Node, const value_type>() const{
				return biterator<Node, const value_type>(_node, _root);
			}

			virtual ~biterator(){};

			node_ptr _max(node_ptr x)
			{
				node_ptr tmp = x;
				while (tmp && tmp->_Rchild != 0)
					tmp = tmp->_Rchild;
				return tmp;
			}

			node_ptr _min(node_ptr x)
			{
				node_ptr tmp = x;
				while (tmp && tmp->_Lchild != 0)
					tmp = tmp->_Lchild;
				return tmp;
			}

    };
}