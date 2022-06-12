#ifndef Y
#define Y
#include "../Vector/Vector.hpp"


namespace ft
{
template <class T, class Container = std::vector<T> >
class stack
{
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef typename container_type::size_type size_type;
        typedef typename container_type::reference reference;
        typedef typename container_type::const_reference const_reference;
        explicit stack(const container_type& container = container_type()) : c(container)
        {
        }
        ~stack() {};
        void push(value_type val){ c.push_back(val); };
        void pop() { c.pop_back(); };
        value_type top() const{ return c.back(); };
        bool empty() { return c.empty(); };
        int size() { return c.size(); };
        void clear() { c.clear(); };

    private:
        container_type c;       
};
}
#endif