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

// is question me humlog ko minimum cost laana hai but ye bhi diya hua hai ki humlog ko maxTime means maxDistace ke and phuchna hai
// basically do paramete pe depend kr rha jo puch rha hai jaise minimum code toh ushko phle check krenge baad me distance ka check krenge;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        int m=edges.size();
        unordered_map<int,vector<pair<int,int>>> adjList;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({passingFees[0],{0,0}});
        vector<int> dis(n,1e9);
        vector<int> fees(n,1e9);
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int f=it.first;
            int d=it.second.first;
            int node=it.second.second;
            if(node==(n-1)) return f;
            for(auto nbr:adjList[node]){
                if(d+nbr.second<=maxTime){
                    if(fees[nbr.first]>f+passingFees[nbr.first]){
                        fees[nbr.first]=f+passingFees[nbr.first];
                        dis[nbr.first]=d+nbr.second;
                        pq.push({fees[nbr.first],{dis[nbr.first],nbr.first}});
                    }
                    else if(dis[nbr.first]>d+nbr.second){
                        // bhle hi us node pe humlog jadacost se phuch rhe hai lkin distance km hai toh is node ko bhi pq me rkhenge kyuki humlog ko cost pe koi condition hai lkin distance pe hai toh sara condition leke chlna hai;
                        dis[nbr.first]=d+nbr.second;
                        pq.push({f+passingFees[nbr.first],{dis[nbr.first],nbr.first}});
                    }
                }
            }
        }
        return -1;
    }
};
