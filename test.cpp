#include <iostream>
#include <map>
#include <string>
#include "test.hpp"

 
// Driver Code
int main()
{
    std::cout << "debug" << std::endl;
    Test<int> test;
    test.new_node();
    test.edit();
    return 0;
}
