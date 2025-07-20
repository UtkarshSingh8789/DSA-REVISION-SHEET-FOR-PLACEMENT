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
    void setEnd(){
        flag=true;
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
    }
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                Node* new_node=new Node();
                node->put(word[i],new_node);
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word) {
        Node* node=root;
        return dfs(word,0,node);
    }
private:
    bool dfs(string& word,int i,Node* node){
        if(i==word.length()){
            return node->flag;
        }
        if(word[i]=='.'){
            for(char ch='a';ch<='z';ch++){
                if(node->containsKey(ch)){
                    if(dfs(word,i+1,node->get(ch))) return true;
                }
            }
            return false;
        }
        else{
            if(!node->containsKey(word[i])) return false;
            return dfs(word,i+1,node->get(word[i]));
        }
    }
};