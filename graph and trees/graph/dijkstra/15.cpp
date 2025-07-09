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

// VVI-> OBSERVATION BASED;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            pq.push({heightMap[i][0],{i,0}});
            visited[i][0]=true;
            pq.push({heightMap[i][n-1],{i,n-1}});
            visited[i][n-1]=true;
        }
        for(int i=0;i<n;i++){
            pq.push({heightMap[0][i],{0,i}});
            visited[0][i]=true;
            pq.push({heightMap[m-1][i],{m-1,i}});
            visited[m-1][i]=true;
        }
        int ans=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int height=it.first;
            int x=it.second.first;
            int y=it.second.second;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && !visited[new_x][new_y]){
                    ans=ans+max(0,height-heightMap[new_x][new_y]);
                    int newHeight=max(height,heightMap[new_x][new_y]);
                    pq.push({newHeight,{new_x,new_y}});
                    visited[new_x][new_y]=true;
                }
            }
        }
        return ans;
    }
};