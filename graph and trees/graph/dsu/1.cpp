#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x==parent_y) return;
        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }
        else if(rank[parent_y]>rank[parent_x]){
            parent[parent_x]=parent_y;
        }
        else{
            parent[parent_y]=parent_x;
            rank[parent_x]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected){
        int n=isConnected.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    Union(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                count++;
            }
        }
        return count;
    }
};