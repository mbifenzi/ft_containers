#include "./Containers/Stack/Stack.hpp"
#include "./Containers/Vector/Vector.hpp"
#include "./Containers/Map/map.hpp"
// #include <map>

int main()
{
    // ft::map<int,int> m;
    // m.insert(ft::make_pair(1,1));
    // m.insert(ft::make_pair(2,2));
    // m.insert(ft::make_pair(3,3));
    // ft::map<int,int>::iterator it = m.end();
    // it--;
    // std::map<int,int> m;
    ft::map<int, int> map;
    map.insert(ft::make_pair(1,1));
    map.insert(ft::make_pair(10,10));
    map.insert(ft::make_pair(51,15));
    map.insert(ft::make_pair(31,31));
    map.insert(ft::make_pair(12,12));
    map.insert(ft::make_pair(22,22));
    map.insert(ft::make_pair(2,2));
    map.insert(ft::make_pair(0,0));
    map.Print();
    // std::cout << " ====== " << it->second << std::endl;
    return(0);

    // std::cout << *it << std::endl;

}
