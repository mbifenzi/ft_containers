#pragma once

#include <iostream>
#include <cstdlib>
#include "../../Utilities/pair.hpp"
#include "../../Iterator/biterator.hpp"
// #include "../../Utilities/fancy_tree.hpp"

#define BLACK 0
#define RED   1

namespace ft
{
    // Node CLASS
    template<typename T>
    class Node 
    {
    public:
        typedef Node<T>* pointer;
        typedef Node<const T>* const_pointer;
        typedef  T value_type;
        T* _data;
        int _color;
        pointer _Rchild;
        pointer _Lchild;
        pointer  _Parent;
        std::allocator<T> _alloc;

        Node()
        {
        };

        Node(const Node& rhs)
        {
            this->_data = rhs._data;
            this->_color = rhs._color;
            this->_Rchild = rhs._Rchild;
            this->_Lchild = rhs._Lchild;
            this->_Parent = rhs._Parent;
        }
        Node &operator=(const Node &rhs)
        {
            this->_data = rhs._data;
            this->_color = rhs._color;
            this->_Rchild = rhs._Rchild;
            this->_Lchild = rhs._Lchild;
            this->_Parent = rhs._Parent;
            return(*this);
        }
        ~Node() { }
    };
        
    // RBT CLASS
    template<typename T, typename Compare ,typename Allocator = std::allocator<T> >
    class rbt
    {
        public:
 public :
        typedef Allocator                                   allocator_type;
        typedef T                                           value_type;
        typedef size_t                                      size_type;
        typedef Node<value_type>*                           pointer;
        typedef Node<value_type>*                           const_pointer;
        typedef Compare                                     key_compare;
        typedef ft::biterator<Node<value_type>, value_type> iterator;
        typedef ft::biterator<Node<value_type>, value_type> const_iterator;
        

    protected:
        key_compare                                             _comp;
        allocator_type                                          _alloc;
        pointer                                                 _root;
        size_t                                                  _size;
        typename Allocator::template rebind<Node<T> >::other    _node_alloc;
        allocator_type                                          _value_alloc;
    public:
        rbt(const key_compare &c = key_compare(), const allocator_type &alloc = allocator_type()): _comp(c), _alloc(alloc)
        {
            _root = NULL;
            _size = 0;
        }
        rbt(const rbt& rhs)
        {
            *this = rhs;
        }
        rbt &operator=(const rbt &rhs)
        {
            this->clear();
            _size = 0;
            this->clone(rhs);
        }
        pointer clone(const rbt &rhs)
        {
            const_iterator it = rhs.begin();
                for(; it != rhs.end(); it++)
                    insert_node(_root, *it);
        }
        pointer new_node(const value_type& value)
        {
            Node<value_type>* node = _node_alloc.allocate(1);
            node->_data = _value_alloc.allocate(1);
            _value_alloc.construct(node->_data, value);
            // std::cout << "new_node" << std::endl;
            node->_Parent = NULL;
            node->_Lchild = NULL;
            node->_Rchild = NULL;
            node->_color = RED;
                // std::cout << node->_data << std::endl;
            return node;
        }

        pointer search(const value_type &k)
        {
                if (!_root)
                    return NULL;
                pointer node = _root;
                while (node)
                {
                        // std::cout << "search" << std::endl;
                    if (!_comp.operator()(k, *node->_data) && !_comp.operator()(*node->_data, k))
                        return node;
                    if (_comp.operator()(k, *node->_data)){
                        node = node->_Lchild;
                    } else{
                        node = node->_Rchild;
                    }
                }
                return NULL;
            }

            pair<iterator,bool> insert (const value_type& val){
                pointer found = search(val);
                if (found)
                    return ft::make_pair(iterator(found, _root), false);
                return ft::make_pair(iterator(insert_node(val), _root), true);
            }

            pointer    insert_node(const value_type& value)
			{
				pointer to_add = new_node(value);
				pointer root = this->_root;
                // return(to_add);
                pointer x = NULL;

                while(root)
				{
            		x = root;
					if (_comp.operator()(*to_add->_data,  *root->_data))
						root = root->_Lchild;
                    else
                        root = root->_Rchild;
                }
                to_add->_Parent = x;
                if (x == NULL)
                {
                    _root = to_add;
                    _root->_color = BLACK;
                    // return ;
                }
                else if (_comp.operator()(*to_add->_data,  *x->_data))
                    x->_Lchild = to_add;
                else
                    x->_Rchild = to_add;
                if ( to_add->_color == RED && x->_color == RED ) 
                    fix_unbalanced(to_add);
                _size++;
                return(to_add);
            }

            void fix_unbalanced(pointer to_add)
            {
                pointer Gparent = NULL;
                pointer parent = NULL;
                pointer uncle = NULL;


                while (to_add != _root && to_add->_color != BLACK && to_add->_Parent && to_add->_Parent->_color == RED)
                {
                    parent = to_add->_Parent;
                    Gparent = parent->_Parent;
                    if (Gparent)
                    {
                        uncle = (Gparent->_Lchild == parent) ? Gparent->_Rchild : Gparent->_Lchild;
                        if (uncle && uncle->_color == RED)
                        {
                            parent->_color = BLACK;
                            uncle->_color = BLACK;
                            Gparent->_color = RED;
                            to_add = Gparent;
                        }
                        else
                        {
                            if (uncle == Gparent->_Rchild)
                            {
                                if (to_add == Gparent->_Rchild)
                                {
                                    leftRotate(parent);
                                    to_add = parent;
                                    parent = to_add->_Parent;
                                }
                                rightRotate(Gparent);
                                std::swap(parent->_color, Gparent->_color);
                                to_add = parent;
                            }
                            else
                            {
                                if (to_add == parent->_Lchild)
                                {
                                    rightRotate(parent);
                                    to_add = parent;
                                    parent = to_add->_Parent;
                                }
                                leftRotate(Gparent);
                                std::swap(parent->_color, Gparent->_color);
                                to_add = parent;
                            }
                        }
                    }
                }
                _root->_color = BLACK;
            }

            void leftRotate(pointer Gparent)
            {
                pointer y = Gparent->_Rchild;
                Gparent->_Rchild = y->_Lchild;
                if (Gparent->_Rchild != NULL)
                    y->_Rchild->_Parent = Gparent;
                y->_Parent = Gparent->_Parent;
                if (Gparent->_Parent == NULL)
                    _root = y;
                else if (Gparent == Gparent->_Parent->_Lchild)
                    Gparent->_Parent->_Lchild = y;
                else
                    Gparent->_Parent = y;
                y->_Lchild = Gparent;
                Gparent->_Parent = y;
            }

            void rightRotate(pointer Gparent)
            {
                pointer y = Gparent->_Lchild;
                Gparent->_Lchild = y->_Rchild;
                if (Gparent->_Lchild != NULL)
                    Gparent->_Lchild->_Parent = Gparent;

                y->_Parent = Gparent->_Parent;
                if (Gparent->_Parent == NULL)
                    _root = y;
                else if (Gparent == Gparent->_Parent->_Rchild)
                    Gparent->_Parent->_Rchild = y;
                else
                    Gparent->_Parent->_Lchild = y;
                y->_Rchild = Gparent;
                Gparent->_Parent = y; 
            }

            size_type erase(const value_type& node)
            {
                pointer found = search(node);
                if (found)
                {
                    erase_node(found);
                    return 1;
                }
                return 0;
            }

            void    erase_node(pointer to_delete)
            {
                if (!to_delete->_Lchild && !to_delete->_Rchild)
                {
                    erase_rebalance(to_delete);
                    pointer parent = to_delete->_Parent;
                    // std::cout << "erase = " << std::endl;
                    if (!parent)
                        _root = NULL;
					else if (parent->_Lchild == to_delete)
						parent->_Lchild = NULL;
					else
						parent->_Rchild = NULL;
					destroy_node(to_delete);
                    _size--;
				}
				else if (to_delete->_Lchild)
                {
					pointer predecessor = _inOrderPredecessor(to_delete);
					_alloc.destroy(to_delete->_data);
					_alloc.construct(to_delete->_data, *(predecessor->_data));
					erase_node(predecessor);
				}
				else
                {
					pointer successor = _inOrderSuccessor(to_delete);
					_alloc.destroy(to_delete->_data);
					_alloc.construct(to_delete->_data, *(successor->_data));
					erase_node(successor);
				}
            }
            pointer	_inOrderSuccessor(pointer pt)
			{
				if(!pt)
					return NULL;
				if(pt->_Rchild != NULL)
					return precised_min(pt->_Rchild);
				pointer	node = pt;
				pointer	parent = node->_Parent;
				while(parent != NULL && node == parent->_Rchild)
				{
					node = parent;
					parent = parent->_Parent;
				}
				return parent;
			};

            pointer	_inOrderPredecessor(pointer pt)
            {
                if(!pt)
                    return NULL;
                if(pt->_Lchild != NULL)
                    return precised_max(pt->_Lchild);
                pointer	node = pt;
                pointer	parent = node->_Parent;
                while(parent != NULL && node == parent->_Lchild)
                {
                    node = parent;
                    parent = parent->_Parent;
                }
                return parent;
            };

            void erase_rebalance(pointer node)
            {
                if (node->_color == RED){
                    //Case 1: Just delete node, tree still valid;
                    return ;
                }
                if (node == _root){
                    //Case 2: remove Double Black from root and return;
                    node->_color = BLACK;
                    return;
                }
                pointer sibling = (node == node->_Parent->_Lchild) ? node->_Parent->_Rchild : node->_Parent->_Lchild;
                if (sibling && sibling->_color == BLACK)
                {
                    if ((!sibling->_Rchild || sibling->_Rchild->_color == BLACK) && 
                        (!sibling->_Lchild || sibling->_Lchild->_color == BLACK))
                    {
                        //Case 3: sibling and it's childrens color is BLACK.
                        sibling->_color = RED;
                        if (node->_Parent->_color == RED)
                        {
                            node->_Parent->_color = BLACK;
                            return;
                        } 
                        else 
                            erase_rebalance(node->_Parent);
                    }
                    if (node == node->_Parent->_Lchild)
                    {
                        if ((!sibling->_Rchild || sibling->_Rchild->_color == BLACK) &&
                            sibling->_Lchild && sibling->_Lchild->_color == RED)
                        {
                        //Case 5: nearst child is RED, and furthest is BLACK;
                        //swap sibling and it's nearst child's colors
                        //Rotate sibling in opposite direction of node
                            std::swap(sibling->_color, sibling->_Lchild->_color);
                            rightRotate(sibling);
                            sibling = node->_Parent->_Rchild;
                        }
                        if (sibling->_Rchild && sibling->_Rchild->_color == RED)
                        {
                        //Case 6: sibling furthest child is Red.
                        //Swap _Parent and sibling color, color furthest child in BLACK;
                        //Rotate _Parent in direction of node.
                            std::swap(node->_Parent->_color, sibling->_color);
                            sibling->_Rchild->_color = BLACK;
                            leftRotate(node->_Parent);
                        }
                    } else{
                        if ((!sibling->_Lchild || sibling->_Lchild->_color == BLACK) &&
                            sibling->_Rchild && sibling->_Rchild->_color == RED){
                        //Case 5
                            std::swap(sibling->_color, sibling->_Rchild->_color);
                            leftRotate(sibling);
                            sibling = node->_Parent->_Lchild;
                        }
                        if (sibling->_Lchild && sibling->_Lchild->_color == RED){
                        //Case 6
                            std::swap(node->_Parent->_color, sibling->_color);
                            sibling->_Lchild->_color = BLACK;
                            rightRotate(node->_Parent);
                        }
                    }
                }
                else if (sibling && sibling->_color == RED)
                {
                    //Case 4: Sibling color is RED. swap _Parent and sibling colors, rotate _Parent in node direction
                    //recursive call to function 
                    std::swap(sibling->_color, node->_Parent->_color);
                    if (node == node->_Parent->_Lchild)
                        leftRotate(node->_Parent);
                    else
                        rightRotate(node->_Parent);
                    erase_rebalance(node);
                }
			}

            void    destroy_node(pointer node){
                _alloc.destroy(node->_data);
                _alloc.deallocate(node->_data, 1);
                _node_alloc.deallocate(node, 1);
            };

            void clear(){
                if (_root){
                    _clear(_root);
                    _root = NULL;
                    _size = 0;
                }
            };

            void    _clear(pointer node){
                if (!node)
                    return;
                if (node->_Lchild)
                    _clear(node->_Lchild);
                if (node->_Rchild)
                    _clear(node->_Rchild);
                pointer parent = node->_Parent;
                if (!parent)
                    _root = NULL;
				else if (parent->_Lchild == node)
					parent->_Lchild = NULL;
				else
					parent->_Rchild = NULL;
                destroy_node(node);
            };

            pointer min()
            {
                pointer node = _root;
                if (!node)
                    return NULL;
                while (node->_Lchild)
                    node = node->_Lchild;
                return node;
            };

            pointer max() const
            {
                pointer node = _root;
                if (!node)
                    return NULL;
                while (node->_Rchild)
                    node = node->_Rchild;
                return node;
            };

            pointer precised_min(pointer node)
            {
                if (!node)
                    return NULL;
                while (node->_Lchild)
                    node = node->_Lchild;
                return node;
            };
            pointer precised_max(pointer node)
            {
                if (!node)
                    return NULL;
                while (node->_Rchild)
                    node = node->_Rchild;
                return node;
            };

            pointer successor(pointer node){
                if (!node)
                    return NULL;
                if (node->_Rchild)
                    return min(node->_Rchild);
                pointer parent = node->_Parent;
                while (parent && parent->_Rchild == node)
                {
                    node = parent;
                    parent = node->_Parent;
                }
                return parent;
            };

            pointer predecessor(pointer node){
                if (!node)
                    return NULL;
                if (node->_Lchild)
                    return max(node->_Lchild);
                pointer parent = node->_Parent;
                while (parent && parent->_Lchild == node)
                {
                    node = parent;
                    parent = node->_Parent;
                }
                return parent;
            };

            pointer root() const
            {
                return _root;
            };

            ~rbt()
            {
                clear();
            }

            pointer getNode()
            {
                return _root;
            }

            bool empty() const{return !_size;};

            size_type size() const{return _size;};

            size_type max_size() const{ return _node_alloc.max_size();};

            size_type capacity() const{return _size;};

            void reserve(size_type){};

            void shrink_to_fit(){};
            
            void swap(rbt& other)
            {
                std::swap(_root, other._root);
                std::swap(_size, other._size);
            };

            iterator find (const value_type& key){
                if (!_root)
                    return iterator(NULL, _root);
                pointer node = _root;
                while (node){
                    if (!_comp.operator()(key, *node->_data) && !_comp.operator()(*node->_data, key))
                        return iterator(node, _root);
                    if (_comp.operator()(key, *node->_data)){
                        node = node->_Lchild;
                    } else{
                        node = node->_Rchild;
                    }
                }
                return iterator(NULL, _root);
            };

            const_iterator find (const value_type& key) const {
                if (!_root)
                    return const_iterator(NULL, _root);
                pointer node = _root;
                while (node){
                    if (!_comp.operator()(key, *node->_data) && !_comp.operator()(*node->_data, key))
                        return iterator(node, _root);
                    if (_comp.operator()(key, *node->_data)){
                        node = node->_Lchild;
                    } else{
                        node = node->_Rchild;
                    }
                }
                return  const_iterator(NULL, _root);
            };

            iterator bound(const value_type& key)
            {
                pointer ret = NULL;
                pointer node = _root;
                while (node){
                    if (_comp.operator()(key, *node->_data)){
                        ret = node;
                        node = node->_Lchild;
                    }
                    else{
                        node = node->_Rchild;
                    }
                }
                return (iterator(ret, _root));
            };
        
            
    };
}
