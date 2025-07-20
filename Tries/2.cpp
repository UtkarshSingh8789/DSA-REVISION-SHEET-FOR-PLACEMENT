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
    Node* links[26]={NULL};
    int cntPrefix=0;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void increasePrefix(){
        cntPrefix++;
    }
};

class Tries{
public:
    Node* root;
    Tries(){
        root=new Node();
    }
    void insert(string& word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                Node* new_node=new Node();
                node->put(word[i],new_node);
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
    }
    int countWordStartingWith(string& word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])) return 0;
            node=node->get(word[i]);
        }
        return node->cntPrefix;
    }
};

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        int n=strs.size();
        Tries t1;
        for(int i=0;i<n;i++){
            t1.insert(strs[i]);
        }
        string ans;
        for(int i=0;i<strs[0].length();i++){
            ans.push_back(strs[0][i]);
            if(t1.countWordStartingWith(ans)<n){
                ans.pop_back();
                break;
            }
        }
        return ans;
    }
};