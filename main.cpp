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
    // mp.insert(ft::make_pair(12,12));
    // mp.insert(ft::make_pair(22,22));
    // mp.insert(ft::make_pair(2,2));
    // mp.insert(ft::make_pair(0,0));
    // map.Print();
    fancy_tree<ft::pair<const int,int> > tree;
    tree.print_tree(mp.getNode(), V_VIEW);
    // std::cout << " ====== " << it->second << std::endl;
    return(0);

    // std::cout << *it << std::endl;

}
