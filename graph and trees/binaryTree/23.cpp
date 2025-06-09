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
    void dfs(TreeNode* root, string& str, string& ans) {
        if(root==NULL) return;
        if(root->left == NULL && root->right == NULL) {
            str.push_back(root->val+'a');
            string reversedStr=str;
            reverse(reversedStr.begin(),reversedStr.end());
            if(ans.empty() || ans>reversedStr){
                ans=reversedStr;
            }
            str.pop_back();
            return;
        }
        str.push_back(root->val+'a');
        dfs(root->left,str,ans);
        dfs(root->right,str,ans);
        str.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        string str;
        string ans;
        dfs(root,str,ans);
        return ans;
    }
};