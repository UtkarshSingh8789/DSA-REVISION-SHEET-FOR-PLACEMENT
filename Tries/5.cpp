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
class MagicDictionary {
public:
    Node* root;
    MagicDictionary() {
        root=new Node();
    }
    void buildDict(vector<string> dictionary) {
        for(int i=0;i<dictionary.size();i++){
            Node* node=root;
            string s=dictionary[i];
            for(int j=0;j<s.length();j++){
                if(!node->containsKey(s[j])){
                    Node* new_node=new Node();
                    node->put(s[j],new_node);
                }
                node=node->get(s[j]);
            }
            node->setEnd();
        }
    }
    bool search(string searchWord) {
        return dfs(0,1,searchWord,root);
    }
private:
    bool dfs(int i,int changes_left,string& s,Node* node){
        if(i==s.length()) return (changes_left==0) && node->flag;
        char curr=s[i];
        if(node->containsKey(curr)){
            if(dfs(i+1,changes_left,s,node->get(curr))) return true;
        }
        if(changes_left>0){
            for(char ch='a';ch<='z';ch++){
                if(ch==curr) continue;
                if(node->containsKey(ch)){
                    if(dfs(i+1,changes_left-1,s,node->get(ch))) return true;
                }
            }
        }
        return false;
    }
};