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
    std::map<int, char> m;
    ft::map<int, char> my_m;
//   std::string res, res1;
     for (size_t i = 0; i < 1e3; i++)
            {
                m.insert(std::make_pair(i, 'X'));
                my_m.insert(ft::make_pair(i, 'X'));
            }
            ft::map<int, char> my_copy_m(my_m);
           
           ft::map<int, char> m1;
        for (int i = 0; i < 10; i++)
            m1.insert(ft::make_pair(i, 'a'));
        ft::map<int, char> copy_m(m1);
        /*-----------------------------------------------------------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, res1;
        /*--------------------------------------------------------*/
        for (ft::map<int, char>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
            res += it->second;

        for (ft::map<int, char>::iterator it = copy_m.begin(); it != copy_m.end(); ++it) // fill res from copy_m
            res1 += it->second;


}
