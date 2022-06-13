#include "./Containers/Stack/Stack.hpp"
#include "./Containers/Vector/Vector.hpp"

int main()
{
    
    ft::vector<int> v;
    // ft::vector<int> v2;
    v.push_back(1);
    v.push_back(11);
    // std::cout << *v.end() << std::endl;
    std::cout << *(v.end() - 1) << std::endl;
    std::cout << *(v.end() - 2) << std::endl;
    // if (it == it2)
    //     std::cout << "it == it2" << std::endl;
    // std::cout << v[1] - v[0] << std::endl;
}