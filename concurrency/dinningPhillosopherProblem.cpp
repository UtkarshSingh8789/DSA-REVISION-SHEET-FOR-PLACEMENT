#include <iostream>
#include <thread>
#include <semaphore>
#include <mutex>
#include <chrono>
using namespace std;
const int NUM_PHILOSOPHERS = 5;
// One binary semaphore for each fork (available = 1, taken = 0)
std::counting_semaphore<1> fork0(1);
std::counting_semaphore<1> fork1(1);
std::counting_semaphore<1> fork2(1);
std::counting_semaphore<1> fork3(1);
std::counting_semaphore<1> fork4(1);
// binary semaphore is for forks;
std::counting_semaphore<1>* forks[NUM_PHILOSOPHERS] = {
    &fork0, &fork1, &fork2, &fork3, &fork4
};
std::counting_semaphore<4> maxPhilosopher(4);// this is created because i am allowing only 4 philosopher at a time; so one philosopher have always a fork to eat;
void Philosopher(int id){
    int left=id;
    int right=(id+1)%5;
    while(true){
        cout<<"philosopher "<<id<<" is thinking"<<endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        maxPhilosopher.acquire();// gives wait signal decreases the count; at fifth philospher count<0 hence it will wait. // max allowed 4 at a time;
        forks[left]->acquire();
        forks[right]->acquire();
        cout<<"philosopher "<<id<<" is eating"<<endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        forks[left]->release();
        forks[right]->release();
        maxPhilosopher.release();
    }
}
int main(){
    thread Philosopher[5];
    for(int i=0;i<5;i++){
        Philosopher[i]=thread(Philosopher,i);
    }
    for(int i=0;i<5;i++){
        Philosopher[i].join();
    }
    return 0;
}

