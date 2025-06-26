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

// this question is easy but the difficulty is that the problem statement is not clear->. basically in this question if you have a keey it doesnot mean that you get the box and you take the candiest. if you have the key then you can opent it for accessing the box you mush have the box;

// in this testcase -> [1,1,1]
// candies =
// [100,1,100]
// keys =
// [[],[0,2],[]]
// containedBoxes =
// [[],[],[]]
// initialBoxes =
// [1]

// output is not 201 because you have inital boxes 1 and you access it and key for box 0 and 2 but you donot have box zero and two, so instead of having their keys you can't access it;
// hence expexted output=1;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& boxes, vector<int>& initialBoxes) {
        int n=status.size();
        int m=initialBoxes.size();
        // you have to trak the boxes you can access and have its status close;
        unordered_set<int> st;
        unordered_map<int,bool> visited;
        queue<int> q;
        for(int i=0;i<m;i++){
            if(status[initialBoxes[i]]==1){
                q.push(initialBoxes[i]);
                visited[initialBoxes[i]]=true;
            }
            else{
                st.insert(initialBoxes[i]);
            }
        }
        int ans=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans=ans+candies[node];
            if(keys[node].size()>0){
                for(int i=0;i<keys[node].size();i++){
                    if(status[keys[node][i]]==0){
                        status[keys[node][i]]=1;
                        // check we can access it or not;
                        if(!visited[keys[node][i]] && st.find(keys[node][i])!=st.end()){
                            st.erase(keys[node][i]);
                            q.push(keys[node][i]);
                            visited[keys[node][i]]=true;
                        }
                    }
                }
            }
            if(boxes[node].size()>0){
                for(int i=0;i<boxes[node].size();i++){
                    if(!visited[boxes[node][i]] && status[boxes[node][i]]==1){
                        q.push(boxes[node][i]);
                        visited[boxes[node][i]]=true;
                    }
                    else if(status[boxes[node][i]]==0){
                        st.insert(boxes[node][i]);
                    }
                }
            }
        }
        return ans;
    }
};