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
    int n;
    int preIndex;
    unordered_map<int,int> m;
    TreeNode* dfs(int s,int e,vector<int>& pre,vector<int>& in){
        if(s>e) return NULL;
        int rootVal=pre[preIndex++];
        TreeNode* root=new TreeNode(rootVal);
        int pos=m[rootVal];
        root->left=dfs(s,pos - 1, pre, in);
        root->right=dfs(pos + 1, e,pre, in);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        n=pre.size();
        preIndex=0;
        m.clear();
        for(int i=0;i<n;i++) {
            m[in[i]]=i;
        }
        return dfs(0,n-1,pre,in);
    }
};