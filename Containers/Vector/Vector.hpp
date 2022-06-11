#ifndef X
#define X

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <climits>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <memory>
#include "../../utilities/enable_if.hpp"
#include "../../iterator/iterator_traits.hpp"
#include "../../iterator/iterator.hpp"

namespace ft
{
template <class T, class Allocator = std::allocator<T> >
class vector
{
    public:
        typedef	T	value_type;
		typedef Allocator allocator_type;
		typedef size_t	size_type;
		typedef	ft::iterator_op<T> iterator;
		typedef ft::reverse_iterator<iterator>	reverse_iterator;
		typedef	ft::iterator_op<const value_type>			const_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef typename	allocator_type::pointer	pointer;
		typedef typename	allocator_type::const_pointer	const_pointer;
		typedef typename	allocator_type::reference	reference;
		typedef typename	allocator_type::const_reference const_reference;
		typedef typename	std::ptrdiff_t							difference_type;

        vector(const allocator_type & alloc= allocator_type()) : _alloc(alloc)
			{
				_capacity = 0;
				this->_data = this->_allocator.allocate(_capacity);
				this->_size = 0;
			};
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(n),  _capacity(n)
		{
			if (n)
			    _data = _allocator.allocate(n);
		    for (size_t i = 0; i < _size; i++)
			    _allocator.construct(&_data[i], val);
		}
        vector(size_type n, const T& value)
        {
            _size = n;
            _capacity = n;
            _data = _alloc.allocate(n);
            for (size_type i = 0; i < n; ++i)
                _alloc.construct(_data[i], value);
        }
        vector(const vector& other)
        {
            _size = other._size;
            _capacity = other._capacity;
            _data = _alloc.allocate(_capacity);
            for (size_type i = 0; i < _size; ++i)
                _alloc.construct(_data[i], other._data[i]);
        }
        vector	&operator= (const vector& other)
		{
			if (this != &other)
			{
				_alloc.deallocate(_data, _capacity);
				_capacity = other._capacity;
				_size = other._size;
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_data[i], other._data[i]);
			}
			return *this;
		}
        
        ~vector ()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			if (_data)
				_alloc.deallocate(_data, _capacity);
		}

    private:
        size_type _size;
        size_type _capacity;
        pointer _data;
        allocator_type		_alloc;
};
}
#endif