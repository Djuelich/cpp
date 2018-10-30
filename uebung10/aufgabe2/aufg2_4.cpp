#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <functional>

// GCC SGI-Extensions!
#include <ext/functional>
#include <ext/algorithm>

using __gnu_cxx::compose1;
using namespace std;

int main(int argc, char** argv)
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    /* bind2nd binds the number 0 as the second parameter of the equal_to function and makes it unary */
    /* bind2nd binds the number 2 as the second parameter of the modulus function and makes it unary */
    /* compse1 uses the modulus function as the parameter of the equals_to function (works because return type of 
       modulus ist the same type as the equal_to parameter) */
    //Note: compose1 always needs unary functions
    /* remove_if removes all elements wich return true (using the given function) by replacing them with the next 
       element than return false. remove_if than returns an iterator to the new end */
    //Note: remove_if doesn't delete the elements past the new end iterator, they are still accessible
    vector<int>::iterator new_end = 
        remove_if(v.begin(), v.end(), 
              compose1(bind2nd(equal_to<int>(), 0),     
                       bind2nd(modulus<int>(), 2)));    
    
    v.erase (new_end, v.end());                                 //Solution 1: erase the elements past the new end

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); //Solution 2: You could replace "v.end()" with "new_end". This 
    cout << endl;                                               //should be done if you still want to use both iterators. 

    return 0;
}
