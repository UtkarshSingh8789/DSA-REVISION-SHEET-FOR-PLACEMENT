#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        pq.push({0,{0,0}});
        dis[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int x=it.second.first;
            int y=it.second.second;
            int d=it.first;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n){
                    int distance=max(d,abs(heights[new_x][new_y]-heights[x][y]));
                    if(dis[new_x][new_y]>distance){
                        dis[new_x][new_y]=distance;
                        pq.push({distance,{new_x,new_y}});
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }
};