#include<bits/stdc++.h>
#include<thread>
#include<unistd.h>
using namespace std;

void taskA()
{
    for(int i = 0; i<10; ++i)
    {
        sleep(1);
        cout<<"TaskA: "<<i<<endl;
        fflush(stdout);
    }
}

void taskB()
{
    for(int i=0; i<10; ++i)
    {
        sleep(1);
        cout<<"TaskB: "<<i<<endl;
        fflush(stdout);
    }
}

int main()
{
    //creating a thread and providing what task to execute using this thread:
    thread t1(taskA);
    thread t2(taskB);
    // two threads are created
    // both the tasks will run parallely
    t1.join();
    t2.join();

    // main thread will wait till t1 and t2 gets executed
    return 0;
}