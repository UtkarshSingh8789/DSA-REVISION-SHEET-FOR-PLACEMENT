#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first.first;
            int y=it.first.second;
            int count=it.second;
            ans=max(ans,count);
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n){
                    if(grid[new_x][new_y]==1){
                        grid[new_x][new_y]=2;
                        q.push({{new_x,new_y},count+1});
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};