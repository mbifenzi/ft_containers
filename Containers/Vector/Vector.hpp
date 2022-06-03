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

namespace ft
{
template <class T, class Allocator = std::allocator<T> >
class Vector
{
    public:
        typedef typename Allocator::reference reference;
        typedef typename Allocator::const_reference const_reference;
        typedef iterator;
        typedef const_iterator;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;
        typedef typename Allocator::pointer iterator;
        typedef typename Allocator::const_pointer const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        Vector()
        {
            _size = 0;
            _capacity = 0;
            _data = nullptr;
        }

        Vector(size_type n)
        {
            _size = n;
            _capacity = n;
            _data = allocator_type::allocate(n);
        }

        Vector(size_type n, const T& value)
        {
            _size = n;
            _capacity = n;
            _data = allocator_type::allocate(n);
            for (size_type i = 0; i < n; ++i)
                allocator_type::construct(_data + i, value);
        }
        
        

    private:
        size_type _size;
        size_type _capacity;
        pointer _data;
};
}
#endif