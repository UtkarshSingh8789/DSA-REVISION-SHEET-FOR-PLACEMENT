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
    Node* links[26]; // every charcter from a->z will store the refrence of other node;
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnds(){
        flag=true;
    }
    ~Node(){
        for(int i=0;i<26;i++){
            if(links[i]){
                delete links[i];
                links[i]=nullptr;
            }
        }
    }
};
class Tries{
public:
    Node* root;
    Tries(){
        root=new Node();
    }
    void insert(string word){
        // while inderting we will always start with root;
        Node* node=root;
        for(int i=0;i<word.length();i++){
            // we have to check either the links of current charcter is null or not;
            if(!node->containsKey(word[i])){
                // if not contain we will put now links[ch-'a] of current node will point to new_Node;
                Node* new_node=new Node();
                node->put(word[i],new_node);
            }
            // if we have put the character then node should point to the refrence of links[ch-'a'];
            node=node->get(word[i]);
        }
        // now if we reach the end then we have to set its flag=true, flag=true means there is a word ending with last charcter this will help in searching the word;
        node->setEnds();
        // T.C-> O(LEN);
    }
    bool search(string word){
        // for searching the word we will again start with root node beacuse evey word begins with root node only hence we will search from that point only;
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])) return false;
            node=node->get(word[i]);
        }
        if(node->flag==true) return true;
        return false;
        // T.C->O(LEN);
    }
    bool startsWith(string preffix){
        // we have to check that given prefix is prefix of any other node or not?
        // hence we have to start with root only;
        Node* node=root;
        for(int i=0;i<preffix.size();i++){
            if(!node->containsKey(preffix[i])) return false;
            node=node->get(preffix[i]);
        }
        return true;
        //T.C->O(len);
    }
    ~Tries(){
        delete root;
    }
};