#pragma once

#include <iostream>

#define BLACK 0
#define RED   1

template <typename T>
class Node 
{
    protected :
        T _data;
        int _color;
        Node *_Rchild;
        Node *_Lchild;
        Node *_Parent;
    public :
        typedef Node<T*> pointer;
        typedef const Node<T*> const_pointer;
        typedef size_t size_type;
        Node(): _color(RED), _Rchild(NULL), _Lchild(NULL), _Parent(NULL) {};
        Node(const& Node<T*> rhs)
        {
            this->_data = rhs._data;
            this->_color = rhs._color;
            this->_Rchild = rhs._Rchild;
            this->_Lchild = rhs._Lchild;
            this->_Parent = rhs._Parent;
        }
        Node &operator=(Node<T*> const &rhs)
        {
            this->_data = rhs->_data;
            this->_color = rhs._color;
            this->_Rchild = rhs._Rchild;
            this->_Lchild = rhs._Lchild;
            this->_Parent = rhs._Parent;
            return(*this);
        }
        ~Node() { }
};

template <typename T>
class Test
{
    public :
        Test() { }
        ~Test() { }
        void new_node() 
        {
            Node<int> *node = new Node<int>(1);
            node->_data = 1;
            node->_color = RED;
            node->_Rchild = NULL;
            node->_Lchild = NULL;
            node->_Parent = NULL;
            delete node;
        }
        void edit()
        {
            node<int> *node = new Node<int>();
            node->_data = 1;
            node<int> *node2 = node;
            // delete node;
            node2->_color = BLACK;
        }
};

