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
        explicit stack(const &container_type &c = container_type()) : container(c)
        {
        };
        ~stack() {};
        void push(T){ container.push_back(T); };
        T pop()
        {
            T tmp = container.back();
            container.pop_back();
            return tmp;
        };
        T top() const{ return container.back(); };
        bool empty() { return container.empty(); };
        int size() { return container.size(); };
        void clear() { container.clear(); };

    private:
        Container container;       
};
}
#endif