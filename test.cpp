#include <iostream>
#include <map>

 
// Driver Code
int main()
{
   std::map<int, int> m;
   std::map<int, int>::iterator it;
    m[1] = 1;
    m[2] = 2;
    m[3] = 3;
    m[4] = 4;
    // it = m.begin();
    for(it = m.begin(); it != m.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    m.erase(m.begin(), m.find(3));
    for(it = m.begin(); it != m.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    return 0;
  
}

