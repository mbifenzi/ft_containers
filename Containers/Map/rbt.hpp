#pragma once

#include <iostream>
#include <cstdlib>

#define BLACK 0
#define RED   1

namespace ft
{
    // Node CLASS
    template<typename T>
    class Node
        {
            typedef Node<T*> pointer;
            typedef const Node<T*> const_pointer;
            typedef size_t size_type;
            Node(): _color(RED), _Rchild(NULL), _Lchild(NULL), _Parent(NULL) {};
            Node(const& Node rhs)
            {
                this->_data = rhs._data;
                this->_color = rhs._color;
                this->_Rchild = rhs._Rchild;
                this->_Lchild = rhs._Lchild;
                this->_Parent = rhs._Parent;
            }
            Node &operator=(Node const &rhs)
            {
                this->_data = rhs._data;
                this->_color = rhs._color;
                this->_Rchild = rhs._Rchild;
                this->_Lchild = rhs._Lchild;
                this->_Parent = rhs._Parent;
                return(*this);
            }
            ~Node() { }

            protected:
                T		_data;
                int		_color;
                pointer	_Rchild;
                pointer	_Lchild;
                pointer	_Parent;
        };
        
    // RBT CLASS
    template<typename T, class Compare ,class Allocator = std::allocator<T> >
    class rbt
    {
        public:
            typedef          T									value_type;
			typedef typename Node<value_type>::pointer          pointer;
			typedef typename Node<value_type>::const_pointer    const_pointer;
			typedef typename Node<value_type>::size_type        size_type;
			typedef typename Allocator                          allocator_type;

    //  
            
            explicit rbt(const Compare &c = Compare(), const Allocator &alloc = allocator_type()) : _comp(c), _alloc(alloc),  _size(0)
            {
            }
            pointer new_node(const value_type& value)
			{
                pointer node = _node_alloc(1);
                node->_data = _value_alloc(1);
                _value_alloc.construct(node->_data, value);
                return node;
            };

            void    insert_node(const value_type& value)
			{
				pointer to_add = new_node(value);
				pointer root = this->_node;
                pointer x = NULL;

                while(root)
				{
            		x = root;
					if (_comp(to_add->_data,  root->_data))
						root = root->_Lchild;
                    else
                        root = root->_Rchild;
                }
                to_add->_Parent = x;
                if (x == NULL)
                {
                    _node = to_add;
                    _node->_color = Black;
                    return ;
                }
                if (_comp(to_add->_data,  x->_data))
                    x->_Lchild = to_add;
                else
                    x->_Rchild = to_add;
                if (to_add->_color == RED && x->_color == RED)
                    fix_unbalanced(to_add->_data);
            }

            void fix_unbalanced(pointer to_add)
            {

            }
        private:
            pointer                             _node;
            Compare                             _comp;
            Allocator                           _value_alloc;
            std::allocator< Node<value_type> >  _node_alloc;
            size_t                              _size;
            
    };
}

