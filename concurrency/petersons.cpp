#include<iostream>
#include<thread>
using namespace std;
bool flag[2]={false,false};
int turn=0;
void peterson(int i){
    int j=1-i;
    flag[i]=true;
    turn=j;
    while(turn==j && flag[j]==true){
        // busy wait;
    }
    cout<<"person "<<i<<" is in the critical section\n"<<endl;
    flag[i]=false;
}
int main(){
    thread p0(peterson,0);
    thread p1(peterson,1);
    p0.join();
    p1.join();
    return 0;
}