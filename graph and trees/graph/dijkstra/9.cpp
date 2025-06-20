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
// second minimum time to reach destination;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        int m=edges.size();
        unordered_map<int,vector<int>> adjList;
        for(int i=0;i<m;i++){
            int u=edges[i][0]-1;
            int v=edges[i][1]-1;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> dis1(n,1e9);
        vector<int> dis2(n,1e9);
        dis1[0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            if(node==n-1 && dis2[n-1]!=1e9) return dis2[n-1];
            int count=it.first;
            int div=count/change;// it denote that if it even then you are at green and if odd then signal is red; for odd we have to think;
            if(div%2!=0){
                count=change*(div+1);
            }
            for(auto nbr:adjList[node]){
                if(count+time<dis1[nbr]){
                    dis2[nbr]=dis1[nbr];
                    dis1[nbr]=count+time;
                    pq.push({count+time,nbr});
                }
                else if(count+time<dis2[nbr] && count+time!=dis1[nbr]){
                    dis2[nbr]=count+time;
                    pq.push({count+time,nbr});
                }
            }
        }
        return -1;
    }
};