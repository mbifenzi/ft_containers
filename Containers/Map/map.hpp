#pragma once

#include <iostream>
#include <memory>
#include "rbt.hpp"
#include <utility>
#include <stdexcept>
#include <functional>
#include "../../Utilities/pair.hpp"
// #include "../../Iterator/biterator.hpp"

namespace ft
{

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
	class map
	{
				
		public:
			class value_compare;
			typedef Key     													key_type;
			typedef T															mapped_type;
			typedef Compare														key_compare;
			typedef Alloc 														allocator_type;
			typedef size_t 														size_type;																						
			typedef ft::pair<const key_type, mapped_type>						value_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::difference_type					difference_type;
			typedef Node<value_type>*											node_ptr;
			typedef typename ft::reverse_iterator<typename rbt<value_type, value_compare, Alloc>::iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<typename rbt<value_type, value_compare, Alloc>::const_iterator>	const_reverse_iterator;
			typedef typename rbt<value_type, value_compare, Alloc>::iterator											iterator;
			typedef typename rbt<value_type, value_compare, Alloc>::const_iterator										const_iterator;
			// typedef typename rbt<value_type, value_compare, Alloc>::node_type											node_type;
			protected:
				key_compare                             _comp;
				allocator_type                          _alloc;
				value_compare                           _value_comp;
				rbt<value_type, value_compare, Alloc>   _rbt;
			public:
			// map() : _rbt() { }
			explicit map(const key_compare &c = key_compare(), const Alloc &alloc = allocator_type()) : 
				_comp(c), _alloc(alloc), _value_comp(c), _rbt(_value_comp, _alloc ) { }

			map(const map &rhs) : _rbt(rhs._rbt), _alloc(rhs._alloc), _comp(rhs._comp) { }

			map &operator=(const map &rhs) { _rbt = rhs._rbt; _alloc = rhs._alloc; _comp = rhs._comp; return(*this); }
			
			template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type(),
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()):
                _comp(comp), _alloc(alloc), _rbt() {
                _rbt.set_compare_alloc(value_compare(comp), alloc);
                while (first != last){
                    _rbt.insert(*first);
                    first++;
                }
            };
			~map() { _rbt.clear();}
			mapped_type operator[](const key_type &key)
			{
				return (_rbt.insert(ft::make_pair(key, mapped_type())).first)->second;
			}
			void insert (const value_type& val)
			{
			 	_rbt.insert(val);
				// std::cout << "inserted " << val.first << " " << val.second << std::endl;
			};
			
					iterator begin() { return(iterator(_rbt.min(), _rbt.root())); }
					const_iterator begin() const { return(const_iterator(_rbt.min, _rbt.root())); }
					iterator end() { return(iterator(_rbt.max()->_Rchild, _rbt.root())); }
					const_iterator end() const { return(const_iterator(_rbt.max()->_Rchild, _rbt.root())); }
					reverse_iterator rbegin() { return reverse_iterator(end()); }
					const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
					reverse_iterator rend() { return reverse_iterator(begin()); }
					const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
					bool empty() const { return(_rbt.empty()); }
					// size_type size() const { return(_rbt.size()); }
					// size_type max_size() const { return(_rbt.max_size()); }
					// void swap(map &rhs) { _rbt.swap(rhs._rbt); }
					// mapped_type &operator[](const key_type &key) { return(_rbt[key]); }
					// mapped_type &at(const key_type &key) { return(_rbt.at(key)); }
	};

	template <class Key, class T, class Compare, class Alloc>
	class map<Key,T,Compare,Alloc>::value_compare : public std::binary_function<value_type, value_type, bool>
	{
		friend class map<Key,T,Compare,Alloc>;
		protected:
			Compare _comp;
		public:
			value_compare(const Compare &c) : _comp(c) { }
			value_compare(){};
			bool operator()(const value_type &lhs, const value_type &rhs) const
			{
				return(_comp(lhs.first, rhs.first));
			}
	};
}
