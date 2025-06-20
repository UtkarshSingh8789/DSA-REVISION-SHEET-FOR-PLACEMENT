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


// A very good question in this we have to to find minimum to visit the last grid cell -> the time taken to move to its neighbour is 1 second and
// you can move to its neighbour only when time spent is greater than or equal to vlaue of the nbr; -> we can revisit the visited cell;

// initially we are at (0,0) we have to move (m-1,n-1) for this  grid[0][1] || grid[1][0] must be  lesss than or equal to 1 so for next move if time is less than neighbour value then we do to-fro movement to pass the time and match the time;
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> time(m,vector<int>(n,1e9));
        pq.push({0,{0,0}});
        time[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int t=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(time[x][y]<t) continue;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n){
                    if(grid[new_x][new_y]<=t+1){
                        if(time[new_x][new_y]>t+1){
                            time[new_x][new_y]=t+1;
                            pq.push({time[new_x][new_y],{new_x,new_y}});
                        }
                    }
                    else if((grid[new_x][new_y]-t)%2!=0){
                        // visualize having to-> fro movement to pass the time;
                        if(time[new_x][new_y]>grid[new_x][new_y]){
                            time[new_x][new_y]=grid[new_x][new_y];
                            pq.push({time[new_x][new_y],{new_x,new_y}});
                        }
                    }
                    else{
                        if(time[new_x][new_y]>grid[new_x][new_y]+1){
                            time[new_x][new_y]=grid[new_x][new_y]+1;
                            pq.push({time[new_x][new_y],{new_x,new_y}});
                        }
                    }
                }
            }
        }
        return time[m-1][n-1];
    }
};