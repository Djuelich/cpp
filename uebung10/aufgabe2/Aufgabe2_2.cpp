#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>

std::minstd_rand0 generator (time(NULL));
std::uniform_int_distribution<int> distribution_1(5,10);
std::uniform_int_distribution<int> distribution_2(33,126); //ascii zeichen zwischen 33 und 126

std::string randomstring()
{   
    std::string s;
    
    for (int i = 0; i < distribution_1(generator); i++)
    {   
        s = s + char(distribution_2(generator));
    }
    
    return s;
}

int main ()
{   
    
    std::vector<std::string> svec (100, "a");
    
    std::generate (svec.begin(), svec.end(), randomstring);
       
    
    // benutzt default "<" operator
    std::sort(svec.begin(), svec.end());

    std::ostream_iterator<std::string> out_it (std::cout,"\n");
    std::copy ( svec.begin(), svec.end(), out_it );
    
    return 0;
}
