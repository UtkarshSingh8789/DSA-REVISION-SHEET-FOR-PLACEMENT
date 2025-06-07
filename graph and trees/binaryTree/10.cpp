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
};// INPORTANT QUESTION PARENT ARRAY KA CONCEPT;
class Solution {
public:
    unordered_map<int,TreeNode*> parent;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        if(root->left){
            parent[root->left->val]=root;
            dfs(root->left);
        }
        if(root->right){
            parent[root->right->val]=root;
            dfs(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent[root->val]=NULL;
        dfs(root);
        unordered_map<int,bool> visited;
        visited[target->val]=true;
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        vector<int> ans;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            auto node=it.first;
            int count=it.second;
            if(count==k){
                ans.push_back(node->val);
            }
            if(node->left!=NULL && !visited[node->left->val]){
                visited[node->left->val]=true;
                q.push({node->left,count+1});
            }
            if(node->right!=NULL && !visited[node->right->val]){
                visited[node->right->val]=true;
                q.push({node->right,count+1});
            }
            if(parent[node->val]!=NULL && !visited[parent[node->val]->val]){
                visited[parent[node->val]->val]=true;
                q.push({parent[node->val],count+1});
            }
        }
        return ans;
    }
};