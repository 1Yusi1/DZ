#include <iostream>
#include <thread>

void threadFunction1(){
    std::cout << "Thread 1\n";
}

void threadFunction2(){
    std::cout << "Thread 2\n";
}
int main(){
    std::thread myThread1(threadFunction1);
    myThread1.join();

    std::thread myThread2(threadFunction2);
    myThread2.join();

    std::thread myThread3([](int i, int j){
        std::cout << i << " " << j << "\n";
     },
    1, 2);
    
    myThread3.join();

    return 0;


}
