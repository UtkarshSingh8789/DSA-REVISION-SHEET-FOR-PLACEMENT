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
    int maxi=0;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(root->left!=NULL && root->right!=NULL && root->left->val==root->val && root->right->val==root->val){
            maxi=max(maxi,left+right);
            return 1+max(left,right);
        }
        else if(root->left!=NULL && root->val==root->left->val){
            maxi=max(maxi,left);
            return 1+left;
        }
        else if(root->right!=NULL && root->val==root->right->val){
            maxi=max(maxi,right);
            return 1+right;
        }
        else{
            return 1;
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};