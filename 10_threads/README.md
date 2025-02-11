# Thread Syncronisation

We are sometimes tasked with running multiple threads either in tandem or in
parallel. std lib provides many methods and techniques for thread syncronisation
to control the execution. Common patters are

1. unique lock + conditiona variable
2. promise and future
3. unique lock + mutex

Each have thier own advantages

## 1. Conditional Variable (sync.cc)

A std::condition_variable can be used to synchronize two threads. One thread signals the other when it has completed its task, allowing the second thread to proceed.

```cpp
void thread1() {

    get unique lock
    // do stuff
    flag = true
    notify thread 2 
    wait on cond var untill flag becomes false
}

void thread2() {

    get unique lock
    wait on cond var untill flag becomes true
    //do stuff
    flag = false
    notify thread 1 
}

```

## 2. Promise and future (sync1.cc)

You can use std::promise and std::future to pass signals between threads. This approach is useful when you want one thread to wait for a signal from another thread before proceeding.

std::prmoise provides a mechanim to write data to a object that can announce the change of state to a future thur its method set_value
std::future provides a method get that is blocked untill a promise is written

Once a future is read , the future becomes invalid.

```cpp
void thread1(std::promise<void> start_signal) {
    // do something
    write to the promise
}

void thread2(std::future<void> start_signal) {
    
    read the future (blocked untill a promise is written)
    // do something
}

int main() {
    create a promise
    create a future
}

```

## 3. Using mutex and a flag (sync2.cc)

You can use a shared variable protected by a std::mutex to coordinate the execution of two threads.

```cpp
create mutex

thread1()
{
   create unique lock on mutex
   while (!flag)
   {
    unlock mutex
    yield thread
    lock mutex
   }
   // do something
   flag = true
}

thread2()
{
    create unique lock on mutex
    while (flag)
    {
        unlock mutex
        yield thread
        lock mutex
    }
    //do something
    flag = false
}
```

In this example, a shared variable (thread1_turn) is used to control which thread executes next. A std::mutex ensures that access to the shared variable is thread-safe.

## Choosing the Right Approach

Use std::condition_variable when you need fine-grained control over thread synchronization and signaling.
Use std::promise and std::future when you want to pass a one-time signal or result between threads.
Use shared variables with std::mutex for simpler tandem execution, but be cautious of potential busy-waiting (e.g., using std::this_thread::yield()).
Each approach has its own use case, and the choice depends on the complexity of the task and the level of synchronization required.
