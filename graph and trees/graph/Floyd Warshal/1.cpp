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
// for every nodes we have find min distance for every nodes hence best approch floyd warshal
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int m=original.size();
        int n=source.length();
        vector<vector<long long>> matrix(26,vector<long long>(26,LONG_MAX));
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j) matrix[i][j]=0;
            }
        }
        for(int i=0;i<m;i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            long long w=cost[i];
            matrix[u][v]=min(matrix[u][v],w);
        }
        vector<vector<long long>> dis=matrix;
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dis[i][k]!=LONG_MAX && dis[k][j]!=LONG_MAX){
                        dis[i][j]=min(dis[i][j],(dis[i][k]+dis[k][j]));
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(dis[u][v]==LONG_MAX) return -1;
            else{
                ans=ans+dis[u][v];
            }
        }
        return ans;
    }
};