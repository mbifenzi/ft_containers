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
#include "../../Utilities/is_integral.hpp"
#include "../../Iterator/iterator_traits.hpp"
#include "../../Iterator/iterator.hpp"
#include "../../Iterator/reverse_iterator.hpp"
#include "../../Utilities/lexi.hpp"
#include "../../Utilities/equal.hpp"

namespace ft
{
template <class T, class Allocator = std::allocator<T> > 
class vector
{
    public:
		typedef	T												value_type;
		typedef Allocator 										allocator_type;
		typedef size_t											size_type;
		typedef typename	allocator_type::pointer				pointer;
		typedef typename	allocator_type::const_pointer		const_pointer;
		typedef typename	allocator_type::reference			reference;
		typedef typename	allocator_type::const_reference 	const_reference;
		typedef	ft::iterator_op<value_type> 					iterator;
		typedef	ft::iterator_op<const value_type>				const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename	std::ptrdiff_t						difference_type;

		explicit vector(const allocator_type & alloc = allocator_type()) : _alloc(alloc)
		{
			_capacity = 0;
			_size = 0;
			_data = 0;
		}

       vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
		{
			_capacity = n;
			_size = n;
			if (n)
				_data = _alloc.allocate(n);
		    for (size_t i = 0; i < _size; i++)
				_alloc.construct(&_data[i], val);
		}

        vector(const vector& other)
        {
            _size = other._size;
            _capacity = other._capacity;
            _data = _alloc.allocate(_capacity);
            for (size_type i = 0; i < _size; ++i)
                _alloc.construct(&_data[i], other._data[i]);
        }

		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type *f = NULL) : _alloc(alloc)
		{
			(void)f;
			difference_type n;
			n = std::distance(first, last);
			if (n < 0)
				n = n * (-1);
			_capacity = n;
			_size = n;
			if(n)
				_data = _alloc.allocate(n);
			for (size_type i = 0; i < _size && first != last ; i++, first++)
				_alloc.construct(&_data[i], *first);
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
		friend	bool operator== (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
		{
			if (lhs.size() !=  rhs.size())
				return false;
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs[i] != rhs[i])
					return false;
			}
			return true;
		}

	  	friend	bool operator!= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) { return !(lhs == rhs); }
		
		friend bool operator< (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)	{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

		friend bool operator >(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) { return  rhs < lhs; }

		friend bool operator <=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) { return !(rhs < lhs); }

		friend bool operator >=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) { return !(lhs < rhs); }

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
		reference at(size_type n) {	
			if (n >= _size)
				throw std::out_of_range("vector::at");
			return _data[n];
		}
		const_reference at(size_type n) const 
		{
			if (n >= _size)
				throw std::out_of_range("vector::at");
			return _data[n];
		}	
		reference front() {	return _data[0];	}
		const_reference front() const {	return _data[0];	}
		reference back() {	return _data[_size - 1];	}
		const_reference back() const {	return _data[_size - 1];	}
		pointer data() {	return _data;	}
		const_pointer data() const {	return _data;	}
		size_type size() const {	return _size;	}
		size_type capacity() const {	return _capacity;	}
		bool empty() const {	return _size == 0;	}

        void    reserve (size_type n)
        {
            if (n > _capacity)
            {
                pointer tmp = _data;
                _data = _alloc.allocate(n);
                if (tmp != NULL)
                {
                    for (size_type i = 0; i < _size; i++)
                        _alloc.construct(_data + i, tmp[i]);
                    _alloc.deallocate(tmp, _capacity);
                }
                _capacity = n;
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
		iterator insert(iterator pos, const value_type& val)
		{
			difference_type p = pos - _data;

			if (_size == _capacity)
			{
				if (_capacity == 0)
					reserve(1);
				else
					reserve(_capacity*2);
			}
			for (difference_type i = _size; i > p; i--)
				_alloc.construct(&_data[i], _data[i - 1]);
			_alloc.construct(&_data[p], val);
			_size++;
			return (_data + p);
		}
		void insert(iterator position, size_type n , const value_type& val)
		{
            size_type o = position - this->begin();
            size_type i = 0;
            size_type k = n;
            if (_size + n > _capacity)
            {
                if (_size + n < _size * 2)
                    reserve(!(_size )? 1 : (_size * 2));
                else
                    reserve(!(_size + n)? 1 : (_size + n ));

            }
            while (_size - i + n > 0)
            {
                if (_size - i == o)
                {
                    while (k--)
                        _alloc.construct(&_data[_size - i + k] , val);
                    break;
                }
                else
                    _alloc.construct(&_data[_size - i + n - 1] , _data[_size - i - 1]);
                i++;
            }
            _size += n;
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
            size_type n = std::distance(first, last);
            size_type i = 0;
            size_type pos = position - begin();
            if (_capacity < _size + n && n <= _size)
                reserve(_capacity * 2);
            else if (_size + n > _capacity)
                reserve(_capacity + n);
            while (_size + n - i > 0)
            {
                if (_size - i == pos)
                {
                    pos = n;
                    try
                    {
                        while (pos--)
                           _alloc.construct(&_data[_size - i + pos], *(--last));
                    }
                    catch (...)
                    {
                        for (size_type i = size(); i != 0; i--)
                        {

                            std::cout << "i =  " << i << std::endl;
                            _alloc.destroy(&_data[i - 1]);
                        }
                        _capacity = 0;
                        throw 3;
                    }
                    break;
                }
                else
                    _alloc.construct(&_data[_size - i + n - 1] ,  _data[_size - i - 1]);
                i++;
            }
            _size += n;
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			size_type n = last - first;
			if (n > _capacity)
			{
				_capacity = n;
				size_type cap = _capacity;
				pointer tmp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(tmp+i, _data[i]);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_data+i);
				_alloc.deallocate(_data, cap);
				_data = tmp;
			}
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data+i, *(first+i));
			_size = n;
		}

		void assign(size_type n, const value_type& val)
		{
			if (n > _capacity)
			{
				_capacity = n;
				size_type cap = _capacity;
				pointer tmp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(tmp+i, _data[i]);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_data+i);
				_alloc.deallocate(_data, cap);
				_data = tmp;
			}
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data+i, val);
			_size = n;
		}

		size_type max_size() const { return _alloc.max_size(); }

		iterator erase(iterator position)
		{
			size_t p = &position - _data;
			for (size_t i = p; i < _size - 1; i++)
				_alloc.construct(_data + i, _data[i + 1]);
			_alloc.destroy(_data + _size - 1);
			_size--;
			return iterator(_data + p);
		}

		iterator erase(iterator first, iterator last)
		{
			iterator ret = first;
				size_type dist = std::distance(begin(), first);
				if (last == end())
				{
					for (;first != last; first++, dist++)
					{
						_alloc.destroy(_data + dist);
						_size--;
					}
				}
				else
				{
					size_type i = 0;
					for (; first != last; first++, dist++)
					{
						if ((last + i) < end())
							std::swap(*first, *(last + i));
						_alloc.destroy(_data + dist);
						_size--;
					}
				}
				return ret;
		}

		void swap(vector& v)
		{
			std::swap(_data, v._data);
			std::swap(_size, v._size);
			std::swap(_capacity, v._capacity);
		}

		allocator_type get_allocator() const
		{
			return (this->_alloc);
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

template <class T, class Alloc>
void	swap(vector<T, Alloc>& a, vector<T, Alloc>& b) { a.swap(b); }

}
#endif