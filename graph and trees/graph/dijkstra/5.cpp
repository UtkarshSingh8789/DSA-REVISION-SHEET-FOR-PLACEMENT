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
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int m=edges.size();
        unordered_map<int,vector<pair<int, double>>> adjList;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adjList[u].push_back({v,prob});
            adjList[v].push_back({u,prob});
        }
        priority_queue<pair<double,int>> q;
        vector<double> prob(n,0.0);
        prob[start_node]=1.0;
        q.push({1.0,start_node});
        while(!q.empty()) {
            auto frontNode=q.top();
            q.pop();
            double currProb=frontNode.first;
            int currNode=frontNode.second;
            if(currProb < prob[currNode]) continue;
            for(auto nbr:adjList[currNode]) {
                int nextNode=nbr.first;
                double edgeProb=nbr.second;
                if(currProb*edgeProb>prob[nextNode]) {
                    prob[nextNode]=currProb*edgeProb;
                    q.push({prob[nextNode],nextNode});
                }
            }
        }
        return prob[end_node];
    }
};