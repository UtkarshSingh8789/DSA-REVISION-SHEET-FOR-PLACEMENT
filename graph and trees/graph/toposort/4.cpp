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
    vector<int> topoSort(unordered_map<int,vector<int>>& adjList,vector<int>& indegree){
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr:adjList[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        if(ans.size()!=indegree.size()) return {};
        return ans;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int,int> grp;
        int count=m;
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                grp[i]=count;
                count++;
            }
            else{
                grp[i]=group[i];
            }
        }
        unordered_map<int,vector<int>> adjList1;
        vector<int> indegree1(n,0);
        unordered_map<int,vector<int>> adjList2;
        vector<int> indegree2(count,0);
        for(int i=0;i<n;i++){
            for(auto it:beforeItems[i]){
                adjList1[it].push_back(i);
                indegree1[i]++;
                int group1=grp[i];
                int group2=grp[it];
                if(group1!=group2){
                    adjList2[group2].push_back(group1);
                    indegree2[group1]++;
                }
            }
        }
        vector<int> vec1=topoSort(adjList1,indegree1);
        vector<int> vec2=topoSort(adjList2,indegree2);
        if(vec1.empty() || vec2.empty()) return {};
        unordered_map<int,vector<int>> umpp;
        vector<int> ans;
        for(int i=0;i<vec1.size();i++){
            int g=grp[vec1[i]];
            umpp[g].push_back(vec1[i]);
        }
        for(auto it:vec2){
            for(auto it1:umpp[it]){
                ans.push_back(it1);
            }
        }
        return ans;
    }
};