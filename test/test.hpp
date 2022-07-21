#pragma once

#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <memory>


#define BLACK 0
#define RED   1

template <class T>
class Node 
{
    public:
        typedef Node<T>* pointer;
        // typedef const Node<T>* const_pointer;
        typedef T value_type;

        T* _data;
        int _color;
        pointer _Rchild;
        pointer _Lchild;
        pointer  _Parent;
        std::allocator<T> _allocator;
        typedef const Node<T*> const_pointer;
        typedef size_t size_type;

        Node(): _color(RED), _Rchild(NULL), _Lchild(NULL), _Parent(NULL)
        {
            _data = _allocator.allocate(1);
            _allocator.construct(_data, value_type);
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

template <class key, class value, class Allocator = std::allocator<std::pair<key, value> > >
class Test
{
    public :
        typedef Node<T>*                    pointer;
        typedef Allocator                   allocator_type;
        Test() { }
        ~Test() { }
        pointer new_node()
        {
            std::cout << "new_node" << std::endl;
            Node<int>* node = _node_alloc.allocate(1);
            return node;
        }
        void edit()
        {
            Node<int>* node = new_node();
            Node<int>* node2 = node;
            node2 = node2->_Rchild;
            std::cout << "edit" << std::endl;
            std::cout << "node->_Rchild" << node->_Rchild->_color << std::endl;
        }
        private:
            typename allocator::template rebind<Node<T*> >::other _node_alloc;
            allocator_type _value_alloc;
};