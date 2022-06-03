#ifndef D
#define D

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
namespace ft
{
    template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class  Reference = T&>
    struct iterator
    {
        typedef Category iterator_category;
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
    };

    template<class iterator>
    class iterator_traits
    {
        typedef typename iterator::iterator_category iterator_category;
        typedef typename iterator::value_type value_type;
        typedef typename iterator::difference_type difference_type;
        typedef typename iterator::pointer pointer;
        typedef typename iterator::reference reference;
    };
    
    };
}
#endif