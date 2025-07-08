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
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        unordered_map<int,vector<vector<int>>> adjList;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int start=edges[i][2];
            int end=edges[i][3];
            adjList[u].push_back({v,start,end});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> time(n,1e9);
        time[0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int t=it.first;
            for(auto it:adjList[node]){
                int nbr=it[0];
                int start=it[1];
                int end=it[2];
                int temp=t;
                if(temp>end) continue;
                if(temp<start) temp=start;
                temp=temp+1;
                if(time[nbr]>temp){
                    time[nbr]=temp;
                    pq.push({temp,nbr});
                }
            }
        }
        return time[n-1]==1e9 ? -1 : time[n-1];
    }
};