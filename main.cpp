#include "./Containers/Stack/Stack.hpp"
#include "./Containers/Vector/Vector.hpp"
#include "./Containers/Map/map.hpp"
#include "./Containers/Set/set.hpp"
#include "./Utilities/fancy_tree.hpp"
#include <signal.h>
#include <sys/time.h>
#include <random>
#include <unistd.h>

// #include <map>
int main()
{
    ft::set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.find(1);

}
