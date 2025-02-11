#include <future>
#include <iostream>
#include <thread>
#include <chrono>
#include <exception>

// this thread gets the pointer to promise object
void worker1(std::promise<int> *p)
{
    while(1)
    {
    std::cout << "worker 1 Simulationg a long running task" << std::endl;
    //put thread to sleep for 5 seconds
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<<"Setting value" << std::endl;
    //set the value of the promise object
    p->set_value(10);
    }
}

void workker2(std::future<int> *f)
{
    while(1)
    {
    std::cout<<"Worker 2 waiting for worker 1 to be done" << std::endl;
    //get the value from the future object
    std::cout<<"From thread " << f->get() << std::endl;
    }
}



int main(void)
{
    //create a promise object
    std::promise<int> p;
    //get the future object from the promise object
    std::future<int> f = p.get_future();
    //create a thread and pass the promise
    std::thread th(worker1,&p);
    std::thread th2(workker2,&f);
    
    //the f.get() will block until the value is set by the worker1 thread using the promise object
    //std::cout<<"From thread " << f.get() << std::endl;
    //wait for the thread to finish

    th.join();
    th2.join();
    return 0;

}

