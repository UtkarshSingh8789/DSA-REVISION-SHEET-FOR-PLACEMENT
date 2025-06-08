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
    int dfs(TreeNode* root,unordered_map<int,int>& h){
        if(root==NULL) return -1;
        int left=dfs(root->left,h);
        int right=dfs(root->right,h);
        h[root->val]=1+max(left,right);
        return h[root->val];
    }
    // if a node is deleted check a another node in the same level and find a node in same level having maximum height;
    // find level of the node an then answer will be the L+H-1;
    //hence to do this we precompute the first and second maximum in each level;
    vector<int> treeQueries(TreeNode* root,vector<int>& queries){
        unordered_map<int,int> h;
        dfs(root,h);
        unordered_map<int,int> first;
        unordered_map<int,int> second;
        unordered_map<int,int> lev;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int firstmaxi=-1,secondmaxi=-1;
            int node_value1=-1,node_value2=-1;
            int level=q.front().second; 
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                TreeNode* node=it.first;
                lev[node->val]=level;
                if(h[node->val]>firstmaxi){
                    secondmaxi=firstmaxi;
                    node_value2=node_value1;
                    firstmaxi=h[node->val];
                    node_value1=node->val;
                }
                else if(h[node->val]>secondmaxi){
                    secondmaxi=h[node->val];
                    node_value2=node->val;
                }
                if(node->left){
                    q.push({node->left,level+1});
                }
                if(node->right){
                    q.push({node->right,level+1});
                }
            }
            first[level]=node_value1;
            second[level]=node_value2;
        }
        int size=queries.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            int level=lev[queries[i]];
            int node1=first[level];
            int node2=second[level];
            if(node1==queries[i]){
                ans[i]=level+(node2==-1?-1:h[node2]);
            }
            else{
                ans[i]=level+h[node1];
            }
        }
        return ans;
    }
};