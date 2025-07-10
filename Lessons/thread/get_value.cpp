#include <iostream>
#include <thread>
#include <future>

using namespace std;

int threadFunction(){
    return 23;
}

int main(){

    promise<int> threadPromise;
    future<int> threadFuture = threadPromise.get_future(); //Получение future из threadPromise


    thread thread1([&threadPromise](){
        threadPromise.set_value(threadFunction());
    });

    int result = threadFuture.get();
    cout << result << "\n";

    thread1.join();
    
}