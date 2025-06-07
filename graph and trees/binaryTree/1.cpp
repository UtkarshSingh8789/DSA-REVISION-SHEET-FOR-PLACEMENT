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
        int lh=dfs(root->left);
        int rh=dfs(root->right);
        int temp=max(lh,rh)+1;
        int ans=max(lh+rh+1,temp);
        maxi=max(maxi,ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxi-1;
    }
};