#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

std::mutex myMutex;
int x = 0;

void incrementVariable() {
    lock_guard<mutex> lock(myMutex);
    x++;
}

void decrementVariable() {
    lock_guard<mutex> lock(myMutex);
    x--;
}

void printHello()
{
    std::cout<<this_thread::get_id()<<" Hello ";
}


int main()
{
    

thread th(printHello);
thread incr(incrementVariable);
thread decr(decrementVariable);


incr.join();
decr.join();

th.join();

cout << "World! "<<this_thread::get_id() << endl;


cout << "Valoarea variabilei "<< x << endl ;


    return 0;
}


