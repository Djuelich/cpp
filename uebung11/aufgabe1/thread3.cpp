#include <iostream>
#include <future>
#include <chrono>
#include <vector>
using namespace std;

int square(int x) {
    return x * x;
}
int main() {

    int square_sum = 0;
    vector < future<int> > fivec;
    
    for (int i = 1; i <= 20; i++)
    {
        fivec.push_back(async(&square, i));
    }

    vector< future<int> >::iterator it;
    for (it = fivec.begin(); it != fivec.end(); it++)
    {
       square_sum += (*it).get();
    }
    cout << "Sum auf squares up to 20 is = " << square_sum << endl;

return 0;
}


