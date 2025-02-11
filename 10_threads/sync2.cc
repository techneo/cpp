#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>

//global variables
//mutex
std::mutex m1;

//flag to indicate if thread 1 is ready
bool thread1_ready = true;

void worker1(void)
{
    while(1)
    {
    //unique lock does not need to be locked 
    //or unlocked explicitly. the lock is removed
    //when the lock goes out of scope
    std::unique_lock<std::mutex> lock(m1);
    while(!thread1_ready)
    {
        //wait for the other thread to be ready
        lock.unlock();
        std::this_thread::yield();
        lock.lock();
    }
    std::cout<<"Running thread 1" << std::endl;
    //put thread to sleep for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //set the flag to true
    thread1_ready = false;

    }
}

void worker2(void)
{
    while(1)
    {
    //get mutex
    std::unique_lock<std::mutex> lock2(m1);
    while(thread1_ready)
    {
        //wait for the other thread to be ready
        lock2.unlock();
        std::this_thread::yield();
        lock2.lock();
    }
    std::cout<<"Running thread 2" << std::endl;
    //put thread to sleep for 2 seconds
    std::this_thread::sleep_for(std::chrono::seconds(2));
    //set the flag to false
    thread1_ready = true;
    //notify the other thread

    }
}

int main(void)
{
    
    //create two threads
    std::thread th1(worker1);
    std::thread th2(worker2);
    //wait for the threads to finish
    th1.join();
    //wait for the threads to finish
    th2.join();
    while(1)
    {
        //put main thread to sleep for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout<<"Exit main"<<std::endl;

}

