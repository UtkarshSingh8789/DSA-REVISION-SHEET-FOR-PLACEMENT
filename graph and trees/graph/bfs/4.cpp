#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> ans(m,vector<int>(n));
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first.first;
            int y=it.first.second;
            int count=it.second;
            ans[x][y]=count;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n){
                    if(!visited[new_x][new_y] && mat[new_x][new_y]==1){
                        visited[new_x][new_y]=true;
                        q.push({{new_x,new_y},count+1});
                    }
                }
            }
        }
        return ans;
    }
};