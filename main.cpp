#include "./Containers/Stack/Stack.hpp"
#include "./Containers/Vector/Vector.hpp"
#include "./Containers/Map/map.hpp"
// #include "./Containers/Set/set.hpp"
#include "./Utilities/fancy_tree.hpp"
// #include <map>

int main()
{
    
    std::map<std::pair<int, int>, std::pair<int, int> >mp;
    mp.insert(std::make_pair(std::make_pair(1,1), std::make_pair(2,2)));
    mp.insert(std::make_pair(std::make_pair(3,3), std::make_pair(4,4)));
    mp.insert(std::make_pair(std::make_pair(5,5), std::make_pair(6,6)));
    // mp.insert(std::make_pair(std::make_pair(1,1), std::make_pair(2,2)));
    // mp.insert(std::make_pair(10,10));
    // mp.insert(std::make_pair(51,15));
    // mp.insert(std::make_pair(31,31));

    std::map<std::pair<int, int>, std::pair<int, int> >::iterator it = mp.begin();
    std::cout << it->first.first << std::endl;
 
    // fancy_tree<ft::pair<const int,int> > tree;
    // tree.print_tree(mp.getNode(), V_VIEW);
    // std::cout << " ====== " << it->second << std::endl;
    return(0);

    // std::cout << *it << std::endl;
}
