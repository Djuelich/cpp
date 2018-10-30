#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

mutex m;

void pow2(int& square_sum, int x)
{     
    m.lock();
    square_sum += x * x;
    m.unlock();
}

int main() 
{   
    
    int square_sum = 0;
    
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

/* Wie wird die Race-Condition durch den Mutex aufgelöst?
 * Der Code der pow2 Funktion kann nicht gleichzeitig von meherern 
 * threads ausgeführt werden. */
