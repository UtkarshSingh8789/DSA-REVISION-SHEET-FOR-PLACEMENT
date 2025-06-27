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

// concept of dfs and binary search together;

class Solution {
public:
    int m;
    unordered_map<int,vector<pair<int,int>>> adjList;
    void dfs(int src,vector<bool>& visited,int ele){
        visited[src]=true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr.first] && nbr.second<=ele){
                dfs(nbr.first,visited,ele);
                // hence all unneccesaay edge we remove itsays that all nodes have 1 incoming edges; no need to check threshold;
            }
        }
    }
    bool isPossible(int ele,int n,int threshold){
        // if we can reach all the node having edge weight less than or equal to ele then it can be our answer no need to check to threshold because if we can reach then other edges having greate weight than ele is removed so all the nodes have atmost one incoming edges and also given thresold>=1;
        vector<bool> visited(n,false);
        dfs(0,visited,ele);
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        m=edges.size();
        int maxi=0;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            maxi=max(maxi,w);
            adjList[v].push_back({u,w});
        }
        int start=1;
        int end=maxi;
        int ans=1000001;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(mid,n,threshold)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        if(ans==1000001) return -1;
        return ans;
    }
};