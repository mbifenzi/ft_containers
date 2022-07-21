#include <iostream>
#include <map>
#include <string>
#include "test.hpp"
#include <cstdlib>
#include <memory>
#include <vector>
#include <algorithm>

#include <utility>

 
// Driver Code
int main()
{
    std::pair<std::string, int> p1("hello", 1);
    Test<std::pair<std::string, int> > test;
    // test.new_node();
    std::cout << "debug" << std::endl;
    test.edit();
    return 0;
}
