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
// in  a binary tree whenever the question asked about shortest path then it must pass through LCA;
class Solution {
public:
    string ans;
    TreeNode* dfs(TreeNode* root,int p,int q){
        if(root==NULL) return NULL;
        if(root->val==p || root->val==q) return root;
        TreeNode* left=dfs(root->left,p,q);
        TreeNode* right=dfs(root->right,p,q);
        if(left==NULL && right==NULL) return NULL;
        if(left==NULL && right!=NULL) return right;
        if(left!=NULL && right==NULL) return left;
        return root;
    }
    void dfs1(TreeNode* node,int startValue,string& str){
        if(node==NULL) return;
        if(node->val == startValue){
            ans+=str;
            return;
        }
        str.push_back('U');
        dfs1(node->left,startValue,str);
        dfs1(node->right,startValue,str);
        str.pop_back();
    }
    void dfs2(TreeNode* node,int destValue,string& str){
        if(node==NULL) return;
        if(node->val == destValue){
            ans+=str;
            return;
        }
        if(node->left){
            str.push_back('L');
            dfs2(node->left,destValue,str);
            str.pop_back();
        }
        if(node->right){
            str.push_back('R');
            dfs2(node->right,destValue,str);
            str.pop_back();
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* node=dfs(root,startValue,destValue);
        string str;
        dfs1(node,startValue,str);
        dfs2(node,destValue,str);
        return ans;
    }
};