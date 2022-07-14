#include "./Containers/Stack/Stack.hpp"
#include "./Containers/Vector/Vector.hpp"
#include "./Containers/Map/map.hpp"
// #include <map>

int main()
{
    ft::map<int,int> m;
    m.insert(ft::make_pair(1,1));
    m.insert(ft::make_pair(2,2));
    // std::map<int,int> m;
    std::cout << " ====== "<< m[1] << std::endl;
    return(0);

    // std::cout << *it << std::endl;

}
