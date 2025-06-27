#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <semaphore>
#include <chrono>
using namespace std;
queue<int> q;// to use fifo behavior first in first out;
const unsigned int MAX_BUFFER_SIZE=5;
mutex mtx;
std::counting_semaphore<MAX_BUFFER_SIZE> empty_Slots(MAX_BUFFER_SIZE);// this semaphore is used to track the count of 
std::counting_semaphore<MAX_BUFFER_SIZE> full_Slots(0);
void Producer(int id){
    int item=0;
    while(item<10){
        // produce 10 item;
        this_thread::sleep_for(chrono::milliseconds(500)); // simulate production time
        empty_Slots.acquire();// decrease the count of empty slots and if buffer is full means empty_slots=0 then it decrease <0 hence wait if buffer id full;
        {
            // enter the critical section by applying lock;
            lock_guard<mutex> lock(mtx);// we use a lock to implement mutual exclusion when both producer and consumer are working;
            cout<<"Producer "<<id<<" is producing "<<item<<endl;
            q.push(item);
        }
        full_Slots.release();// increase the count of full;
        item++;
    }
}
void Consumer(int id){
    int item;
    // we will not do while(!q.empty()) if we do this then if q.empty() it will not run and exits immediately donot wait for the producer to produce;
    while(true){
        full_Slots.acquire();// decreases the count of full slots initially the full slot is zero now full <0 hence initially consumer wait until the signal is send
        {
            lock_guard<mutex> lock(mtx);
            if(!q.empty()){
                auto it=q.front();
                q.pop();
                item=it;
                cout<<"Consumer "<<id<<" consumed_items "<<item<<endl;
            }
        }
        empty_Slots.release();
        this_thread::sleep_for(chrono::milliseconds(800));
    }
}
int  main(){
    thread p1(Producer, 1);
    thread p2(Producer, 2);
    thread c1(Consumer, 1);
    thread c2(Consumer, 2);
    p1.join();
    p2.join();// wait for p1 and p2 completely before moving forward;Since each producer produces only 10 items, they will finish naturally, and we wait for them to complete.
    c1.detach();  //The main thread to exit cleanly after the producers finish.The consumers to continue running in the background (or terminate with the program exit;
    c1.detach();
    // if we use join here also then the main thread will hang forever because the consumers never finish naturally.Consumers run in while(true), consuming indefinitely.
    return 0;
}

