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
#include "../../Utilities/enable_if.hpp"
#include "../../Iterator/iterator_traits.hpp"
#include "../../Iterator/iterator.hpp"

namespace ft
{
template <class T, class Allocator = std::allocator<T> >
class vector
{
    public:
		typedef	T	value_type;
		typedef Allocator allocator_type;
		typedef size_t	size_type;
		typedef	ft::iterator_op<value_type> iterator;
		typedef std::reverse_iterator<iterator>	reverse_iterator;
		typedef	ft::iterator_op<const value_type>			const_iterator;
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef typename	allocator_type::pointer	pointer;
		typedef typename	allocator_type::const_pointer	const_pointer;
		typedef typename	allocator_type::reference	reference;
		typedef typename	allocator_type::const_reference const_reference;
		typedef typename	std::ptrdiff_t							difference_type;

        vector(const allocator_type & alloc= allocator_type()) : _alloc(alloc)
			{
				_capacity = 0;
				this->_data = this->_alloc.allocate(_capacity);
				this->_size = 0;
			};
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n),  _capacity(n)
		{
			if (n)
			    _data = _alloc.allocate(n);
		    for (size_t i = 0; i < _size; i++)
			    _alloc.construct(&_data[i], val);
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
		iterator begin() {	return iterator(_data);	}
		iterator end() {	return iterator(_data + _size);	}
		const_iterator begin() const {	return const_iterator(_data);	}
		const_iterator end() const {	return const_iterator(_data + _size);	}
		reverse_iterator rbegin() {	return reverse_iterator(end());	}
		reverse_iterator rend() {	return reverse_iterator(begin());	}
		const_reverse_iterator rbegin() const {	return const_reverse_iterator(end());	}
		const_reverse_iterator rend() const {	return const_reverse_iterator(begin());	}
		reference operator[] (size_type n) {	return _data[n];	}
		const_reference operator[] (size_type n) const {	return _data[n];	}
		reference at(size_type n) {	return _data[n];	}
		const_reference at(size_type n) const {	return _data[n];	}
		reference front() {	return _data[0];	}
		const_reference front() const {	return _data[0];	}
		reference back() {	return _data[_size - 1];	}
		const_reference back() const {	return _data[_size - 1];	}
		pointer data() {	return _data;	}
		const_pointer data() const {	return _data;	}
		size_type size() const {	return _size;	}
		size_type capacity() const {	return _capacity;	}
		bool empty() const {	return _size == 0;	}
		void reserve(size_type n)
		{
			if (n > _capacity)
			{
				_capacity = n;
				pointer new_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&new_data[i], _data[i]);
				_alloc.deallocate(_data, _capacity);
				_data = new_data;
			}
		}
		void resize(size_type n, const value_type& val = value_type())
		{
			if (n > _capacity)
			{
				_capacity = n;
				pointer new_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&new_data[i], _data[i]);
				_alloc.deallocate(_data, _capacity);
				_data = new_data;
			}
			if (n > _size)
			{
				for (size_type i = _size; i < n; i++)
					_alloc.construct(&_data[i], val);
			}
			else
			{
				for (size_type i = n; i < _size; i++)
					_alloc.destroy(&_data[i]);
			}
			_size = n;
		}
		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			_size = 0;
		}
		void push_back(const value_type& val)
		{
			if (_size == _capacity)
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            _alloc.construct(_data + _size, val);
			_size++;
		}
		void pop_back()
		{
			if (_size > 0)
			{
				_alloc.destroy(&_data[_size - 1]);
				_size--;
			}
		}
		void insert(iterator pos, const value_type& val)
		{
			if (_size == _capacity)
			{
				_capacity *= 2;
				pointer new_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&new_data[i], _data[i]);
				_alloc.deallocate(_data, _capacity);
				_data = new_data;
			}
			for (size_type i = _size; i > pos - _data; i--)
				_alloc.construct(&_data[i], _data[i - 1]);
			_alloc.construct(&_data[pos - _data], val);
			_size++;
		}
		void insert(iterator position, size_type n , const value_type& val)
		{
			if (n > 0)
			{
				if (_size + n > _capacity)
				{
					_capacity = _size + n;
					pointer new_data = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&new_data[i], _data[i]);
					_alloc.deallocate(_data, _capacity);
					_data = new_data;
				}
				for (size_type i = _size; i > position - _data; i--)
					_alloc.construct(&_data[i], _data[i - 1]);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_data[position - _data + i], val);
				_size += n;
			}
		}
		void insert (iterator position, InputIterator first, InputIterator last)
		{
			
		}
		void erase(iterator pos)
		{
			for (size_type i = pos - _data; i < _size - 1; i++)
				_alloc.construct(&_data[i], _data[i + 1]);
			_alloc.destroy(&_data[_size - 1]);
			_size--;
		}
		void erase(iterator first, iterator last)
		{
			for (size_type i = first - _data; i < _size - (last - first); i++)
				_alloc.construct(&_data[i], _data[i + (last - first)]);
			for (size_type i = _size - (last - first); i < _size; i++)
				_alloc.destroy(&_data[i]);
			_size -= (last - first);
		}
		void swap(vector& v)
		{
			std::swap(_data, v._data);
			std::swap(_size, v._size);
			std::swap(_capacity, v._capacity);
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