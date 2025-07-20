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
    bool flag=false;
    Node* links[10];
    bool containsKey(char ch){
        return (links[ch-'0']!=NULL);
    }
    void put(char ch,Node* node){
        links[ch-'0']=node;
    }
    Node* get(char ch){
        return links[ch-'0'];
    }
    void setEnds(){
        flag=true;
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
        }
        node->setEnds();
    }
    bool startWith(string prefix){
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])) return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        Tries t1;
        for(int i=0;i<n1;i++){
            string s=to_string(arr1[i]);
            t1.insert(s);
        }
        int maxi=0;
        for(int i=0;i<n2;i++){
            string s=to_string(arr2[i]);
            for(int j=1;j<=s.length();j++){
                if(t1.startWith(s.substr(0,j))){
                    maxi=max(maxi,j);
                }
            }
        }
        return maxi;
    }
};