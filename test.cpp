#include <iostream>
#include <map>
#include <string>

 
// Driver Code
int main()
{
   std::map<std::string, int> m;
    m["1"] = 1;
    m["2"] = 2;
    m["3"] = 3;
    m["3"] = 4;
    m["5"] = 5;
    m["6"] = 6;
    m["7"] = 7;
    m["8"] = 8;

   std::map<std::string, int>::reverse_iterator it( m.rend() );
   it--;
    std::cout << it->first << " " << it->second << std::endl;

    return 0;
  
}

