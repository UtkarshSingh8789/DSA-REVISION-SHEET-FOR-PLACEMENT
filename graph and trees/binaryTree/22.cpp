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
    unordered_map<TreeNode*,int> dp;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        if(dp.count(root)) return dp[root];
        int not_take=solve(root->left)+solve(root->right);
        int take=root->val;
        if(root->left){
            take=take+solve(root->left->left)+solve(root->left->right);
        }
        if(root->right){
            take=take+solve(root->right->left)+solve(root->right->right);
        }
        return dp[root]=max(take,not_take);
    }
    int rob(TreeNode* root) {
        int ans=solve(root);
        return ans;
    }
};