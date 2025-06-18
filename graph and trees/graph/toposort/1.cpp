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


// you wil find for row and col separarte and check for jth col if ith row is same then we will put element;
class Solution {
public:
    int K;
    vector<int> topoSort(unordered_map<int,list<int>>& adjList,vector<int>& indegree){
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr:adjList[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        if(ans.size()!=K) return {};// ye inportant edges case hai;
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        int m=rowConditions.size();
        int n=colConditions.size();
        K=k;
        unordered_map<int,list<int>> adjList1;
        vector<int> indegree1(k+1,0);
        indegree1[0]=1;
        for(int i=0;i<m;i++){
            int u=rowConditions[i][0];
            int v=rowConditions[i][1];
            adjList1[u].push_back(v);
            indegree1[v]++;
        }
        unordered_map<int,list<int>> adjList2;
        vector<int> indegree2(k+1,0);
        indegree2[0]=1;
        for(int i=0;i<n;i++){
            int u=colConditions[i][0];
            int v=colConditions[i][1];
            adjList2[u].push_back(v);
            indegree2[v]++;
        }
        vector<int> topo1=topoSort(adjList1,indegree1);
        vector<int> topo2=topoSort(adjList2,indegree2);
        if(topo1.empty() || topo2.empty()) return {};
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(topo1[i]==topo2[j]){
                    ans[i][j]=topo1[i];
                }
            }
        }
        return ans;
    }
};