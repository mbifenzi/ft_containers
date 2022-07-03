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
                T		 ;
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
            typedef typename iterator<T>                        

    //  ----------------------------------------------------------------
            
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
                pointer x = to_add;
                pointer y = x->_Parent;
                pointer z = y->_Parent;
                if (z->_Lchild == y )
                    z->_Lchild = x;
                else
                    z->_Rchild = x;
                x->_Parent = z;
                y->_Parent = x;
                x->_Rchild = y;
                y->_Lchild = NULL;
                y->_color = BLACK;
                x->_color = RED;
                if (x->_Parent->_color == RED)
                    fix_unbalanced(x->_data);
            }

            void    erase_node(const value_type& value)
            {
                pointer root = this->_node;
                pointer x = NULL;
                pointer y = NULL;
                pointer z = NULL;
                while(root)
                {
                    x = root;
                    if (_comp(value,  root->_data))
                        root = root->_Lchild;
                    else
                        root = root->_Rchild;
                }
                if (x == NULL)
                    return ;
                y = x->_Lchild;
                if (y == NULL)
                    y = x->_Rchild;
                if (y == NULL)
                {
                    if (x->_Parent == NULL)
                        _node = NULL;
                    else
                    {
                        if (x->_Parent->_Lchild == x)
                            x->_Parent->_Lchild = NULL;
                        else
                            x->_Parent->_Rchild = NULL;
                    }
                    _node_alloc.destroy(x);
                    _node_alloc.deallocate(x, 1);
                    return ;
                }
                z = y;
                while (z->_Lchild)
                    z = z->_Lchild;
                if (z->_Rchild)
                {
                    if (z->_Parent == x)
                        x->_Rchild = z->_Rchild;
                    else
                    {
                        z->_Parent->_Lchild = z->_Rchild;
                        z->_Rchild->_Parent = z->_Parent;
                    }
                    z->_Rchild = NULL;
                }
                else
                {
                    if (z->_Parent == x)
                        x->_Rchild = NULL;
                    else
                    {
                        z->_Parent->_Lchild = NULL;
                    }
                }
                if (x->_Parent == NULL)
                    _node = y;
                else
                {
                    if (x->_Parent->_Lchild == x)
                        x->_Parent->_Lchild = y;
                    else
                        x->_Parent->_Rchild = y;
                }
                y->_Parent = x->_Parent;
                _   node_alloc.destroy(x);
                _node_alloc.deallocate(x, 1);
                if (y->_color == BLACK)
                    fix_unbalanced(y->_data);
            }



            void    clear()
            {
                pointer root = this->_node;
                pointer x = NULL;
                pointer y = NULL;
                pointer z = NULL;
                while(root)
                {
                    x = root;
                    if (root->_Lchild)
                        root = root->_Lchild;
                    else
                        root = root->_Rchild;
                    _node_alloc.destroy(x);
                    _node_alloc.deallocate(x, 1);
                }
                _node = NULL;
            }

            void    print_tree()
            {
                pointer root = this->_node;
                pointer x = NULL;
                pointer y = NULL;
                pointer z = NULL;
                while(root)
                {
                    x = root;
                    if (root->_Lchild)
                        root = root->_Lchild;
                    else
                        root = root->_Rchild;
                    std::cout << x->_data << " ";
                }
                std::cout << std::endl;
            }

            ~rbt()
            {
                clear();
            }

        protected:
            Compare										_comp;
            Allocator									_alloc;
            pointer										_node;
            size_type									_size;
            allocator_type								_node_alloc;
            allocator_type								_value_alloc;
        // private:
        //     pointer                             _node;
        //     Compare                             _comp;
        //     Allocator                           _value_alloc;
        //     std::allocator< Node<value_type> >  _node_alloc;
        //     size_t                              _size;
            
    };
}
