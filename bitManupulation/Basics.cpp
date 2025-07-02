#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// A-> PRINTING THE BINARY REPRESENTATION OF ANY NUMBER;

// CONCEPT-> 5->00000101 -> consept-> hr ek bit ko lsb pe leke jaao mtlb right shif kro and lsb nikalte jaao using and operator;
// i=0-> 5>>0 lsb 1,5>>1 lsb 0,5>>2 lsb 1 and so on... since we have to print like msb to lsb so loop from 31 to 0 (32 bit integer)

void pr_binary(int num){
    for(int i=31;i>=0;i--){
        cout<<((num>>i)&1);
    }
    cout<<endl;
}

//B-> CHECK IF THE ITH BIT IS SET OR NOT AND COUNT THE NUMBER OF SET BIT;;

// CONCEPT-> it bit agr set hoga toh ith 1 leke jaayenge aur & operator lgayenge agr 1 aaya toh set hai;
bool checkForSetbits(int num,int i){
    int ele=1<<i;
    int val=num&ele;
    if(val==0){
        return false;
    }
    return true;
}// kisi bhi number x me log(x) bit hote hai;

// INPORTANT-> AGR KISI NUMBER X ME (EVEN) ITNA HI SETBIT HOGA JITNA X/2 ME HOGA;
// AGR X ODD HUA TOH JITNA SETBIT X/2 ME HAI +1;
int countSetBitApproch1(int n){
    int count=0;
    for(int i=0;i<32;i++){
        if((n&(1<<i))!=0) count++;
    }
    return count;
    // t.c(0(32));
}
int countSetBitApproch2(int n){
    // not when we do n&(n-1) then it reset the first set bit;
    int count=0;
    while(n>0){
        n=(n&(n-1));
        count++;
    }
    //TC -> O(k); where k is number of set bit;
    return count;
}
//C-> CHECK FOR POWER OF 2 AND 4;

// CONCEPT-> if the number is of power of two then it has only set bit and the (x&(x-1))=0;
// if a number is power of 4 then it should must be power of 2 and if divided by 3 leaves remainder 1;
bool checkForPowerOfTwo(int num){
    if(num<=0) return false;
    return (num&(num-1))==0;
}
bool isPowerOfFour(int n) {
    if(n<=0) return false;
    if((n&(n-1))==0 && n%3==1){
        return true;
    }
    return false;
}
//D-> SOME COOL OPERATION AND PLAYING WITH CHARACTER;

// CONCEPT1-> 'A'-> (65 to 90)
//            'a'-> (97 to 122) -> observe 97-65=32 means pow(2,5) means in lowercase 5th bit is set and in uppercase 5 the bit is unset only difference in this and all the things are same;

// A-> 0100 0001
// 1<<5 ->0010 0000
// a-> 0110 0001  ---> (65+32)  => (0110 0001);
// a= char('A' | (1<<5))  [(1<<5)==3]==' ' [[[[[[[[[[[[[[[[hence a=char('A' | ' ')]]]]]]]]]]]]]];
// A= char('a' & ~(1<<5)) [[[[[[[[[[[[[[[[[['c'&'_'=='C]]]]]]]]]]]]]]]]]]]]];
char toLower(char ch) {
    return ch | ' ';
}
char toUpper(char ch) {
    return ch & '_';
}
// Function to find a letter's position [1-26] in the alphabet (case-insensitive)
int letterPosition(char ch) {
    return ch & 31; // AND with 0001 1111 to extract last 5 bits
}

// E-> CLEARING THE SET BITS UPTO ITH BITS STARTS CAN BE FROM MSB AND LSB RESPECTIVELY;

// CONCEPT-> let a=0011 1011 i=4 from lsb
//                 0011 1011 -> convert this into 0010 0000
//               & 1110 0000 -> mask we have to create this
//                 0010 0000
// for creating mask observe this
// 1 ko left shif 1<<(i+1) 1<5 0010 0000
// subtract from -1            0001 1111
// jha 1 wha 0 jha 0 wha 1   (~) leliye (1110 0000) mask created;

int clearBitUptoFromLSB(int num,int i){
    int a=num;
    int mask=~((1<<(i+1))-1);
    return a&mask;
}
int clearBitUptoFromMSB(int num,int i){
    int a=num;
    int mask=((i<<(i+1))-1);
    return a&mask;
}

// SWAP TWO NUMBER WITHOUT USING SWAP INBUILT FUNCTION;

void Swap(int a,int b){
    a=a^b;
    b=b^a;
    a=a^b;
}





