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

// in this question it is said that a grid having cell value 0 -> empty cell, a grid value having cell value 1 -> obstacle;
// we have to find minimum obstace remobal to reach end of grid to do this we can thaught tha if the nbr cell has obstacle then weight is 1 and if not obstace then weight is zero 
// now run dijkstra to solve this question;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dis(m,vector<int>(n,1e9));
        pq.push({0,{0,0}});
        dis[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int x=it.second.first;
            int y=it.second.second;
            int w=it.first;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n){
                    if(grid[new_x][new_y]==1){
                        if(dis[new_x][new_y]>w+1){
                            dis[new_x][new_y]=w+1;
                            pq.push({w+1,{new_x,new_y}});
                        }
                    }
                    else{
                        if(dis[new_x][new_y]>w){
                            dis[new_x][new_y]=w;
                            pq.push({w,{new_x,new_y}});
                        }
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }
};