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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,vector<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first->val;
            int v=it.second.first;
            int l=it.second.second;
            mpp[v][l].push_back(node);
            if(it.first->left){
                q.push({it.first->left,{v-1,l+1}});
            }
            if(it.first->right){
                q.push({it.first->right,{v+1,l+1}});
            }
        }
        for(auto it:mpp){
            vector<int> vec;
            for(auto it2:it.second){
                sort(it2.second.begin(),it2.second.end());
                for(int val:it2.second){
                    vec.push_back(val);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};