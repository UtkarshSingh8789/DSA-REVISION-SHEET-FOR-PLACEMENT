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
//MOST OPTIMIZED SOLUTION
class Solution {
public:
    int n;
    int i=0;
    TreeNode* dfs(int upperbound,vector<int>& preorder){
        if(i==n || preorder[i]>upperbound){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=dfs(root->val,preorder);
        root->right=dfs(upperbound,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n=preorder.size();
        int upperbound=1e9;
        TreeNode* ans=dfs(upperbound,preorder);
        return ans;
    }
};//VVI