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
    Node* links[26];
    int cntPreffix=0;
    int cntEndWith=0;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPreffix++;
    }
    void reduceEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPreffix--;
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
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                Node* new_node=new Node();
                node->put(word[i],new_node);
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWordsEqualTo(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])) return 0;
            node=node->get(word[i]);
        }
        return node->cntEndWith;
    }
    int countWordsStartingWith(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])) return 0;
            node=node->get(word[i]);
        }
        return node->cntPreffix;
    }
    void erase(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])) return;
            node=node->get(word[i]);
            node->reducePrefix();
        }
        node->reduceEnd();
    }
    ~Tries(){
        delete root;
    }
};