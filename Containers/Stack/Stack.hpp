#ifndef Y
#define Y

template <T, Container = std::vector<T>>
class Stack
{
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef typename container_type::size_type size_type;
        typedef typename container_type::reference reference;
        typedef typename container_type::const_reference const_reference;
        typedef typename container_type::iterator iterator;
        typedef typename container_type::const_iterator const_iterator;
        explicit Stack(const &container_type &c = container_type()) : container(c)
        {
        };
        ~Stack(){};
        void push(T)
        {
            container.push_back(T);
        };
        };
        T pop()
        {
            T tmp = container.back();
            container.pop_back();
            return tmp;
        };
        T top();
        bool empty();
        bool full();
        int size();
        void clear();
        void print();
    private:
        Container container;       
};

#endif