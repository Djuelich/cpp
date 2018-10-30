#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include <time.h>

std::minstd_rand0 generator (time(NULL));
std::uniform_int_distribution<int> distribution(1,100);

int randomnumber()
{      
    return distribution(generator);
}


int main ()
{   
    //create vector with size 100, filled with 0
    std::vector<int> ivec (100, 0);
    
    //Fill vector with random numbers.
    std::generate (ivec.begin(), ivec.end(), randomnumber);

    
    std::ostream_iterator<int> out_it (std::cout,"\n");
    std::copy ( ivec.begin(), ivec.end(), out_it );
    
    return 0;

}
