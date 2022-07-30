#include "./Containers/Stack/Stack.hpp"
#include "./Containers/Vector/Vector.hpp"
#include "./Containers/Map/map.hpp"
// #include "./Containers/Set/set.hpp"
#include "./Utilities/fancy_tree.hpp"
// #include <map>

int main()
{
    
    std::map<int, int> mp;

    mp.insert(std::make_pair(10,10));
    mp.insert(std::make_pair(51,15));
    mp.insert(std::make_pair(31,31));
    mp.insert(std::make_pair(66,66));
    mp.insert(std::make_pair(77,77));

    std::map<int,int>::iterator it;
    it  = mp.begin();
    std::map<int,int>::const_iterator ite(it);
    ite = ++it;
    ite->second = 100;
    // ft::map<int,int>::const_iterator i2(it);
    std::cout << ite->second << std::endl;
    // mp.erase(it);

    // std::cout << it->first << std::endl;
 
    // fancy_tree<ft::pair<const int,int> > tree;
    // tree.print_tree(mp.getNode(), V_VIEW);
    // std::cout << " ====== " << it->second << std::endl;
    return (0);
}
