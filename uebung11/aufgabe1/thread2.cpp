#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
using namespace std;



void pow2(atomic <int>& square_sum, int x)
{
    square_sum += x * x;
}

int main() 
{
    atomic <int> square_sum (0);

    vector<thread> threads;
    for (int i = 1; i <= 20; i++)
    {
        threads.push_back(thread(&pow2, ref(square_sum), i));
    }

    vector<thread>::iterator it;
    for (it = threads.begin(); it != threads.end(); it++)
    {
       (*it).join();
    }
    cout << "Sum auf squares up to 20 is = " << square_sum << endl;
    return 0;
}

/* Warum kann es bei der direkten Verwendung eines Atomic-Containers hier keinen
 * Deadlock geben? */
/*  */
