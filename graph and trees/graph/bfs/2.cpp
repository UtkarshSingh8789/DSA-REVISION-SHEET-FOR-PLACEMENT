#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_map<int,vector<pair<int,int>>> umpp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]!='.' && matrix[i][j]!='#'){
                    umpp[matrix[i][j]-'A'].push_back({i,j});
                }
            }
        }
        queue<pair<int,pair<int,int>>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        if(matrix[0][0]=='.'){
            q.push({0,{0,0}});
            visited[0][0]=true;
        }
        else{
            int ele=matrix[0][0]-'A';
            for(auto it:umpp[ele]){
                q.push({0,{it.first,it.second}});
                visited[it.first][it.second]=true;
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int count=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==(m-1) && y==(n-1)) return count;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && matrix[new_x][new_y]!='#' && !visited[new_x][new_y]){
                    if(matrix[new_x][new_y]=='.'){
                        visited[new_x][new_y]=true;
                        q.push({count+1,{new_x,new_y}});
                    }
                    else{
                        int ele=matrix[new_x][new_y]-'A';
                        for(auto it:umpp[ele]){
                           if(!visited[it.first][it.second]){
                             q.push({count+1,{it.first,it.second}});
                            visited[it.first][it.second]=true;
                           }
                        }
                    }
                }
            }
        }
        return -1;
    }
};