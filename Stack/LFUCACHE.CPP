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
struct Node{
    int key;
    int val;
    int freq;
    Node* prev;
    Node* next;
    Node(int k,int v){
        key=k;
        val=v;
        freq=1;
        prev=NULL;
        next=NULL;
    }
};
class DoublyLinkedList{
public:
    Node* head;
    Node* tail;
    int size;
    DoublyLinkedList(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void insertAfterHead(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
        size++;
    }
    void deleteNodeFromTail(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        nextNode->prev=prevNode;
        prevNode->next=nextNode;
        size--;
    }
    bool isEmpty(){
        return (size==0);
    }
};
class LFUCache{  
private:
    int capacity;
    int minFreq;
    unordered_map<int,Node*> umpp;
    unordered_map<int, DoublyLinkedList*> freqToList;  
    void updateFrequency(Node* node){
        // 1 node ka current frequency nikalo;
        // 2 us current frequency se current linkedlist nikalo jisme ye node hai kyuki humko delte krna hai
        // 3 agr current frequency min frequency ke brabr hai and cureed linkedlist empty hai toh minFrequency bdha do
        // 4 update krdo node ka frequency;
        // 5 agr update frequency ke corresponding koi likedlist nhi hai mtlb freqTolist me nhi hai updated frequency toh phir new doubly likedlist create kro;;
        // 6. updated frequency ke corresponding linkedlist me node ko daaldo;

        int currentFreq=node->freq;
        DoublyLinkedList* currList=freqToList[currentFreq];
        currList->deleteNodeFromTail(node);
        if(currentFreq==minFreq && currList->isEmpty()){
            minFreq++;
        }
        node->freq++;
        if(freqToList.find(node->freq)==freqToList.end()){
            // naya linkedlist create krenge;
            freqToList[node->freq]=new DoublyLinkedList();
        }
        freqToList[node->freq]->insertAfterHead(node);
    }
public:
    LFUCache(int capcity){
        this->capacity=capacity;
        minFreq=0;
    }
    int get(int key) {
        if(umpp.find(key) == umpp.end()) {
            return -1;
        }
        Node* node=umpp[key];
        updateFrequency(node);
        return node->val;
    }
    void put(int key,int value){
        if(capacity==0) return;
        if(umpp.find(key)!=umpp.end()){
            Node* node=umpp[key];
            node->val=value;
            updateFrequency(node);
        }
        else{
            if(umpp.size()==capacity){
                // miFreq ke corresponding linkedList nikalo
                // min freq ka tail ka prev node ko delete krdo and map se bhi erase krdo;
                DoublyLinkedList* list=freqToList[minFreq];
                Node* tal=list->tail->prev;
                list->deleteNodeFromTail(tal);
                umpp.erase(tal->key);
                delete tal;
            }
            Node* newnode=new Node(key,value);
            minFreq=1;// adding newNode minFreq=1;
            if(freqToList.find(minFreq)==freqToList.end()){
                freqToList[minFreq]=new DoublyLinkedList();
            }
            freqToList[minFreq]->insertAfterHead(newnode);
            umpp[key]=newnode;
        }
    }
};

