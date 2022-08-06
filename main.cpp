#include "./Containers/Stack/Stack.hpp"
#include "./Containers/Vector/Vector.hpp"
#include "./Containers/Map/map.hpp"
// #include "./Containers/Set/set.hpp"
#include "./Utilities/fancy_tree.hpp"
#include <signal.h>
#include <sys/time.h>
#include <random>
#include <unistd.h>
// #include <map>

int main()
{
    // std::cout << "Hello World!" << std::endl;
    ft::map<ft::pair<int,int>, ft::pair<int,int> > map;
    map.insert(ft::make_pair(ft::make_pair(1,1),ft::make_pair(2,2))); ;
    // {
    //     std::cout << it->first << " " << it->second << std::endl;
    // }
    return (0);
}
