#include "./Containers/Stack/Stack.hpp"
#include "./Containers/Vector/Vector.hpp"

int main()
{
    ft::vector<int> t;
    ft::vector<int> v;
    t.push_back(12);
    t.push_back(343);
    t.push_back(7);

    ft::vector<int>::iterator it;
    for(it = t.begin(); it != t.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::sort(t.begin(), t.end());
       for(it = t.begin(); it != t.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << *t.rbegin() << std::endl;

    
}