#pragma once

#include <iostream>
#include <memory>
#include "rbt.hpp"
#include "../../Utilities/pair.hpp"
#include "../../Iterator/iterator_traits.hpp"
#include "../../Iterator/iterator.hpp"
#include <memory>
#include <iterator>
#include <stdexcept>
#include <functional>

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
    class map
    {
		
        public:
            typedef Key     										key_type;
            typedef T												mapped_type;
            typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef typename ft::pair<const key_type,mapped_type>	value_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename Node<value_type>::node_ptr				node_ptr;
			typedef typename Node<value_type>::node_ptr const		const_node_ptr;
			class value_compare;
			typedef value_compare value_compare;
			typedef typename ft::rbt<value_type, value_compare>
            typedef size_t			                                size_type;
            typedef iterator_traits<iterator>::difference_type		difference_type;
			
            class value_compare
			{
				protected:
					key_compare _comp;
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			}
            map() {}
        
        private:
            
    };
} 

