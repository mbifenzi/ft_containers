#include "./Containers/Stack/Stack.hpp"
#include "./Containers/Vector/Vector.hpp"

int main()
{
    
    ft::vector<int> t;
    t.push_back(1000);
    t.push_back(2);
    t.insert(t.begin(), -1);
    std::cout << *t.begin() << std::endl;
}