#include <iostream> 
#include <thread> 
#include <chrono> 
#include <algorithm> 
#include <string> 
#include "main.h"

//Globals
using namespace std::chrono;
using ull = unsigned long long; 

int myAmount = 0;
int X=0, Y=0;
std::mutex m1, m2;

//Functions
void doSomeWorkForSeconds( int seconds) { std::this_thread::sleep_for(std::chrono::seconds(seconds)); }



void incrementXY(int & XforY, std::mutex& m, const char* desc)
{
    int count=5;
    for (size_t i = 0; i < count; i++)
    {
        m.lock();
            ++XforY;
        std::cout << desc << XforY << '\n';
        m.unlock();
        doSomeWorkForSeconds(1);
    }    
}


void consumeXY() 
{
    int count = 5, XplusY = 0;
    while(1)
    {
        int lockResult = std::try_lock(m1, m2);
        if(lockResult == -1)
        {
            --count;
            XplusY += X+Y;
            X=0;
            Y=0;
            std::cout << "XplusY " << XplusY << std::endl;
        }
        m1.unlock();
        m2.unlock();
        if(count == 0) break;
    }
}



void addMoney()
{
    ull count = 1000000;
    for (size_t i = 0; i < count; i++)
    {
        if(std::try_lock(m1, m2)) {
            ++myAmount;
            m1.unlock();
            m2.unlock();
        }
    }
}

int main(int argc, char const *argv[])
{
    std::cout << std::endl;
    // std::thread t1(addMoney);
    // std::thread t2(addMoney);
    // std::thread t3(addMoney);
    std::thread t4(incrementXY, std::ref(X), std::ref(m1), "X ");
    std::thread t5(incrementXY, std::ref(X), std::ref(m2), "Y ");
    std::thread t6(consumeXY);

    auto begin = std::chrono::high_resolution_clock::now();

    std::cout << "main()" << std::endl;

        // t1.join();
        // t2.join();
        // t3.join();
    t4.join();
    t5.join();
    t6.join();

    // std::cout << myAmount << std::endl;
    
    auto end = std::chrono::high_resolution_clock::now();
    auto time = duration_cast<milliseconds>(end - begin);

    std::cout << "after main()" << std::endl;
    std::cout << "Time : " << time.count() << " ms"<< std::endl;
    std::cout << std::endl;
    return 0;
}
