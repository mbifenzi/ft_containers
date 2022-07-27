#include "./Containers/Stack/Stack.hpp"
#include "./Containers/Vector/Vector.hpp"
#include "./Containers/Map/map.hpp"
// #include "./Containers/Set/set.hpp"
#include "./Utilities/fancy_tree.hpp"
// #include <map>

int main()
{
    
    ft::map<int, int> mp;
    mp.insert(ft::make_pair(1,1));
    mp.insert(ft::make_pair(10,10));
    mp.insert(ft::make_pair(51,15));
    mp.insert(ft::make_pair(31,31));


    ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ret =  mp.equal_range(2);
    std::cout << ret.first->first << std::endl;
 
    // fancy_tree<ft::pair<const int,int> > tree;
    // tree.print_tree(mp.getNode(), V_VIEW);
    // std::cout << " ====== " << it->second << std::endl;
    return(0);

    // std::cout << *it << std::endl;

}
