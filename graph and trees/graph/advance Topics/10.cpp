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


// Conceptual-> 

// for first tree -> find the number of nodes which are at even distance for every node
// for second tree -> find the number of nodes whuch are at odd distance for every node;
class Solution {
public:
    unordered_set<int> st1;
    unordered_map<int,vector<int>> adjList1;
    unordered_map<int,bool> visited1;
    int ans=0;
    void dfs(int src,int count){
        visited1[src]=true;
        if(count%2==0 && st1.find(src)==st1.end()){
            ans++;
            st1.insert(src);
        }
        for(auto nbr:adjList1[src]){
            if(!visited1[nbr]){
                dfs(nbr,count+1);
            }
        }
    }
    unordered_map<int,vector<int>> adjList2;
    int ans1=0;
    void dfs1(int src,int count){
        visited1[src]=true;
        if(count%2!=0 && st1.find(src)==st1.end()){
            ans1++;
            st1.insert(src);
            cout<<src;
        }
        for(auto nbr:adjList2[src]){
            if(!visited1[nbr]){
                dfs1(nbr,count+1);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size();
        int numNodes1=n+1;
        for(int i=0;i<n;i++){
            int u=edges1[i][0];
            int v=edges1[i][1];
            adjList1[u].push_back(v);
            adjList1[v].push_back(u);
        }
        vector<int> vec(numNodes1);
        dfs(0,0);
        for(int i=0;i<numNodes1;i++){
            if(st1.find(i)!=st1.end()){
                vec[i]=ans;
            }
            else{
                vec[i]=numNodes1-ans;
            }
        }
        st1.clear();
        visited1.clear();
        int m=edges2.size();
        int numNodes2=m+1;
        for(int i=0;i<m;i++){
            int u=edges2[i][0];
            int v=edges2[i][1];
            adjList2[u].push_back(v);
            adjList2[v].push_back(u);
        }
        vector<int> vec1(numNodes2);
        dfs1(0,0);
        for(int i=0;i<numNodes2;i++){
            if(st1.find(i)!=st1.end()){
                vec1[i]=numNodes2-ans1;
            }
            else{
                vec1[i]=ans1;
            }
        }
        vector<int> ans(numNodes1);
        int maxi=*max_element(vec1.begin(),vec1.end());
        for(int i=0;i<numNodes1;i++){
            ans[i]=maxi+vec[i];
        }
        return ans;
    }
};