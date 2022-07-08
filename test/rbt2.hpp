#pragma once

#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <memory>
#include <iterator>
#include <utility>


#define BLACK 0
#define RED   1

template <typename T, class alloc = std::allocator<T> >
class Node 
{
    public:
        typedef Node<T>* pointer;
        typedef alloc allocator_type;
        typedef  T value_type;

        T* _data;
        int _color;
        pointer _Rchild;
        pointer _Lchild;
        pointer  _Parent;

        Node(): _color(RED), _Rchild(NULL), _Lchild(NULL), _Parent(NULL)
        {
            // _data = _value_alloc.allocate(1);
            // _value_alloc.construct(_data, 11);
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

template <typename T, typename Compare, class allocator = std::allocator<T> >
class rbt
{
    public :
        typedef allocator                                   allocator_type;
        typedef T                                           value_type;
        typedef Node<value_type>*                           pointer;
        typedef Node<value_type>*                           const_pointer;
        typedef Compare                                     key_compare;

    protected:
        key_compare                                             _comp;
        allocator_type                                          _alloc;
        pointer                                                 _node;
        size_t                                                  _size;
        typename allocator::template rebind<Node<T> >::other    _node_alloc;
        allocator_type                                          _value_alloc;
    public:
        rbt(const key_compare &c, const allocator_type &alloc): _comp(c), _alloc(alloc)  { }
        rbt(const rbt& rhs)
        {
            this->_comp = rhs._comp;
            this->_alloc = rhs._alloc;
            this->_node = rhs._node;
            this->_size = rhs._size;
            this->_node_alloc = rhs._node_alloc;
            this->_value_alloc = rhs._value_alloc;
        }
        rbt &operator=(const rbt &rhs)
        {
            this->_comp = rhs._comp;
            this->_alloc = rhs._alloc;
            this->_node = rhs._node;
            this->_size = rhs._size;
            this->_node_alloc = rhs._node_alloc;
            this->_value_alloc = rhs._value_alloc;
            return(*this);
        }
        ~rbt() { }
        pointer new_node(const value_type& value)
        {
            std::cout << "new_node" << std::endl;
            Node<value_type>* node = _node_alloc.allocate(1);
            node->_data = _value_alloc.allocate(1);
            _value_alloc.construct(node->_data, value);
            return node;
        }
        void insert(const value_type& value)
        {
            Node<value_type>* node = new_node(value);
            Node<value_type>* node2 = node;
            node2 = node2->_Rchild;
            std::cout << "edit" << std::endl;
            // node->_Rchild->_color = BLACK;
            std::cout << "node->_data = " << node->_data << std::endl;
        }

};