// #include<iostream>
// #include<thread>
// #include<semaphore>
// using namespace std;
// std::counting_semaphore<1> sem(1);
// void usePrinter(int id){
//     cout<<"Process "<<id<< " want to use Printer"<<endl;
//     sem.acquire();// send the waith signal decrease the count of other process and if count<0 the processes wait;
//     cout<<"process "<<id<< " is using the printer"<<endl;
//     this_thread::sleep_for(chrono::seconds(2));
//     cout<<"process "<<id<< " is done printing"<<endl;
//     sem.release();
// }
// int main(){
//     thread t1(usePrinter,1);
//     thread t2(usePrinter,2);
//     t1.join();
//     t2.join(); //wait for both threads to fininsh before ending program;
//     return 0;
// }


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
using namespace std;
// Semaphore class
class Semaphore {
private:
    int count;
    mutex mtx; //locks or mutex is used to implement mutual exclusion to avoid race around condition;
    condition_variable cv;
public:
    Semaphore(int init = 0) : count(init) {}
    void wait() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]() { return count > 0; });
        count--;
    }
    void signal() {
        unique_lock<mutex> lock(mtx);
        count++;
        cv.notify_one();
    }
};
// Shared semaphore
Semaphore sem(1); // acts as a binary semaphore (mutex)
void critical_section(int id) {
    sem.wait(); // acquire lock
    cout << "Thread " << id << " is in the critical section.\n";
    this_thread::sleep_for(chrono::milliseconds(1000)); // simulate work
    cout << "Thread " << id << " is leaving the critical section.\n";
    sem.signal(); // release lock
}

int main() {
    vector<thread> threads;
    for(int i = 0; i < 5; i++) {
        threads.push_back(thread(critical_section, i));
    }
    for(auto& th : threads) {
        th.join();
    }
    return 0;
}
