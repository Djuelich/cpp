#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "Summierer.hpp"


int main ()
{   

    Summierer s1;
    
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(99);
    v.push_back(14);
    v.push_back(15);
    

    s1 = std::for_each (v.begin(), v.end(), s1);
    
    /*
    std::cout << "Vector: " << std::endl;
    
    copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    */
    
    std::cout << "Summer des Vectors ist: " << s1.getSumme() << std::endl;
    
    return 0;

}
