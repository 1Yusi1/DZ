#include <iostream>
#include <thread>
#include <future>

using namespace std;

int main(int argc, char* argv[]){

    future<void> asyncFuture1 = async(launch::async, [](){
        for(int i = 0; i < 8; i++){
            cout << "1\n";
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    });

    future<void> asyncFuture2 = async(launch::async, [](){
    for(int i = 0; i < 8; i++){
        cout << "2\n";
        this_thread::sleep_for(chrono::milliseconds(100));
        }
    });
    
}