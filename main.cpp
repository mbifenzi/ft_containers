#include "./Containers/Stack/Stack.hpp"
#include "./Containers/Vector/Vector.hpp"

int main()
{
    std::vector<std::string> t(10, "fill constructor test");
    // t.push_back(1000);
    // t.push_back(2);
    // t.insert(t.begin(), -1);
    // t.erase(t.begin());
    std::cout << *t.begin() << std::endl;
}   