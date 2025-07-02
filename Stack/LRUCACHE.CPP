// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

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
// step 1 use double linked list concept make a separate class;
struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k,int v){
        key=k;
        val=v;
        prev=NULL;
        next=NULL;
    }
};// this is the structure of the doubly linkedlist;
// making a separate class for handling the features of Doubly Linkedlist;
class DoublyLinkedList{
    // constructor bna dete hai taaki jaise hi ye class se object kriye ho ek head pointer and tail pointer bn jaye;
public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }// constructor automatically ek baar hi call hoga jb object bnega;
    void insertAfterHead(Node* node){
        // for first node tail is (-1,-1)
        // node->next=head->next(tail);
        // node->prev=head;
        // tail->prev i.e head->next->prev=node;
        // now for second upcoming node this is our 
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;// now node is tail for other;
    }
    void deleteNodeFromTail(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        nextNode->prev=prevNode;
        prevNode->next=nextNode;
    }
};
class LRUCache {
private:
    int capacity;
    unordered_map<int,Node*> umpp;
    DoublyLinkedList dll;   // object bna constructor automatically call hoga and head and tail node bnjayega;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    int get(int key) {
        if(umpp.find(key)==umpp.end()){
            return -1;
        }
        Node* node=umpp[key];
        dll.deleteNodeFromTail(node);
        dll.insertAfterHead(node);
        return node->val;
    }
    void put(int key, int value) {
        if(umpp.find(key)!=umpp.end()){
            // agr phle se hi toh bhs update krna hai value;
            Node* node=umpp[key];
            node->val=value;
            dll.deleteNodeFromTail(node);
            dll.insertAfterHead(node);
        }
        else{
            // to check krenge ki kya umpp.size()==capacity hai hai toh jo tail node hai start me constructor bnaya tha uska jo prev node hai ushko delte krenge;
            if(umpp.size()==capacity){
                Node* tal=dll.tail->prev;
                dll.deleteNodeFromTail(tal);
                // phir map se htana bhi hoga kyuki permannetly hta rhe;
                umpp.erase(tal->val);
                delete tal;
            }
            Node* newnode=new Node(key,value);
            dll.insertAfterHead(newnode);
            umpp[key]=newnode;
        }
    }
};
int main() {
    int capacity;
    cout<<"Enter LRU Cache capacity: ";
    cin>>capacity;
    LRUCache lru(capacity);
    int operations;
    cout<<"Enter number of operations: ";
    cin >>operations;
    cout<< "Enter operations:\n";
    cout<< "For get: 1 key\n";
    cout<< "For put: 2 key value\n";
    for(int i=0;i<operations;++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int key;
            cin >> key;
            int result = lru.get(key);
            cout << "Get(" << key << ") = " << result << endl;
        } else if (op == 2) {
            int key, value;
            cin >> key >> value;
            lru.put(key, value);
            cout << "Put(" << key << ", " << value << ")" << endl;
        } else {
            cout << "Invalid operation code. Use 1 for get, 2 for put.\n";
        }
    }
    return 0;
}