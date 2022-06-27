#include "./Containers/Stack/Stack.hpp"
#include "./Containers/Vector/Vector.hpp"

int main()
{
    ft::vector<int> t;
    t.push_back(12);
    t.push_back(343);
    t.push_back(7);
    t.push_back(8);
    t.push_back(9);

    ft::vector<int>::iterator it = t.begin() + 1;
    int i = 2;
    it += i;
    std::cout << *it << std::endl;
    it + 1;
}
