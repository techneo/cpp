# Thread Syncronisation

We are sometimes tasked with running multiple threads either in tandem or in
parallel. std lib provides many methods and techniques for thread syncronisation
to control the execution. Common patters are

1. unique lock + conditiona variable
2. promise and future
3. unique lock + mutex

Each have thier own advantages

## 1. Conditional Variable
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

}```

