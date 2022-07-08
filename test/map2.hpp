#pragma once

#include <iostream>
#include <memory>
#include "rbt2.hpp"
#include <utility>
#include <stdexcept>
#include <functional>

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< std::pair<const Key, T> > >
class map
{
            
    public:
        class value_compare;
        typedef Key     																							key_type;
        typedef T																									mapped_type;
        typedef Compare																								key_compare;
        typedef Alloc 																								allocator_type;
        typedef size_t 																								size_type;																						
        typedef typename std::pair<const key_type, mapped_type>													    value_type;
        typedef typename allocator_type::reference																reference;
        typedef typename allocator_type::const_reference														const_reference;
        typedef typename allocator_type::pointer																	pointer;
        typedef typename allocator_type::const_pointer															const_pointer;
        // typedef typename ft::reverse_iterator<typename rbt<value_type, value_compare, Alloc>::iterator>			reverse_iterator;
        // typedef typename ft::reverse_iterator<typename rbt<value_type, value_compare, Alloc>::const_iterator>	const_reverse_iterator;
        // typedef typename rbt<value_type, value_compare, Alloc>::iterator											iterator;
        // typedef typename rbt<value_type, value_compare, Alloc>::const_iterator										const_iterator;
        // typedef typename rbt<value_type, value_compare, Alloc>::node_type											node_type;
        protected:
            rbt<value_type, value_compare, Alloc>   _rbt;
            allocator_type                          _alloc;
            key_compare                             _comp;
            value_compare                           _value_comp;
        public:
        // map() : _rbt() { }
        explicit map(const key_compare &c = key_compare(), const Alloc &alloc = allocator_type()) : 
            _comp(c), _alloc(alloc),_value_comp(c), _rbt(_value_comp, _alloc ) { }
        map(const map &rhs) : _rbt(rhs._rbt), _alloc(rhs._alloc), _comp(rhs._comp) { }
        map &operator=(const map &rhs) { _rbt = rhs._rbt; _alloc = rhs._alloc; _comp = rhs._comp; return(*this); }
        ~map() { }
                // iterator begin() { return(_rbt.begin()); }
                // const_iterator begin() const { return(_rbt.begin()); }
                // iterator end() { return(_rbt.end()); }
                // const_iterator end() const { return(_rbt.end()); }
                // reverse_iterator rbegin() { return(_rbt.rbegin()); }
                // const_reverse_iterator rbegin() const { return(_rbt.rbegin()); }
                // reverse_iterator rend() { return(_rbt.rend()); }
                // const_reverse_iterator rend() const { return(_rbt.rend()); }
                // bool empty() const { return(_rbt.empty()); }
                // size_type size() const { return(_rbt.size()); }
                // size_type max_size() const { return(_rbt.max_size()); }
                // void swap(map &rhs) { _rbt.swap(rhs._rbt); }
                // mapped_type &operator[](const key_type &key) { return(_rbt[key]); }
                // mapped_type &at(const key_type &key) { return(_rbt.at(key)); }
};

template <class Key, class T, class Compare, class Alloc>
class map<Key,T,Compare,Alloc>::value_compare
{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
  friend class map;
protected:
  Compare comp;
  value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
public:
  typedef bool result_type;
  typedef value_type first_argument_type;
  typedef value_type second_argument_type;
  bool operator() (const value_type& x, const value_type& y) const
  {
    return comp(x.first, y.first);
  }
};
