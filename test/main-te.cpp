#include <map>
#include <iostream>
#include <utility>



int main()
{
    std::map<int, int> mp;
  
    // insert elements in random order
    mp.insert({ 2, 30 });
    mp.insert({ 1, 40 });
    mp.insert({ 3, 60 });
  
    // does not inserts key 2 with element 20
    mp.insert({ 2, 20 });
    mp.insert({ 5, 50 });
  
    // prints the elements
    std::cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        std::cout << itr->first
             << '\t' << itr->second << '\n';
    }
}