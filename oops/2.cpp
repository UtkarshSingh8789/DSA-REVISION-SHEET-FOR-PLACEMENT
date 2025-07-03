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
// setter is used to set the private values ans getter is used to get the private values;
// encapsulation is wrapping of data and members in a single unit called class;
// class is the blue print of object;
// any entities in the real world is called object;
class Graph{
    public:
    unordered_map<int,vector<int>> adjList;
    void addEdges(int u,int v,bool directed){
        adjList[u].push_back(v);
        if(!directed){
            adjList[v].push_back(u);
        }
    }
    void printingAdjList(){
        cout<<"AdjList"<<endl;
        for(auto it:adjList){
            cout<<it.first<<" -> ";
            for(auto nbr:adjList[it.first]){
                cout<<nbr<<" ";
            }
            cout<<endl;
        }
    }
    void dfsHelper(int node,unordered_map<int,bool>& visited){
        cout<<node<<" ";
        visited[node]=true;
        for(auto nbr:adjList[node]){
            if(!visited[nbr]){
                dfsHelper(nbr,visited);
            }
        }
    }
    void dfs(int start){
        unordered_map<int,bool> visited;
        cout << "\nDFS traversal from node " << start << ": ";
        dfsHelper(start,visited);
        cout<<endl;
    }
    void bfs(int start){
        queue<int> q;
        unordered_map<int,bool> visited;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cout<<node<<" ";
            for(auto nbr:adjList[node]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
        }
        cout<<endl;
    }
};
int main() {
    Graph g;
    int n,m;
    cout<<"Enter number of nodes:";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    bool directed;
    cout<<"Is the graph directed? (1 for Yes / 0 for No): ";
    cin>>directed;
    cout<<"Enter edges (u v) format:\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdges(u,v,directed);
    }
    g.printingAdjList();
    int startNode;
    cout<<"\nEnter starting node for DFS and BFS: ";
    cin>>startNode;
    g.dfs(startNode);
    g.bfs(startNode);
    return 0;
}
