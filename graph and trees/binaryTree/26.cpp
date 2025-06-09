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

//BRUTE FORCE O(N*M);

class Solution {
public:
    void dfs(TreeNode*root ,int targetSum,int& count,long long sum){
        if(root==NULL) return;
        sum=sum+root->val;
        if(sum==targetSum){
            count++;
        }
        dfs(root->left,targetSum,count,sum);
        dfs(root->right,targetSum,count,sum);
    }
    void solve(TreeNode* root,int targetSum,int& count){
        if(root==NULL) return;
        dfs(root,targetSum,count,0);
        solve(root->left,targetSum,count);
        solve(root->right,targetSum,count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        solve(root,targetSum,count);
        return count;
    }
};

// MOSTOPTIMIZED O(N+M);
// CONCEPT OF PREFIX SUM IN BINARY TREE;
class Solution {
public:
    unordered_map<long long,int> umpp;
    int dfs(TreeNode* root,long long sum,int targetSum){
        if(root==NULL) return 0;
        sum=sum+root->val;
        int count=0;
        if(umpp.find(sum-targetSum)!=umpp.end()){
            count=count+umpp[sum-targetSum];
        }
        umpp[sum]++;
        count=count+dfs(root->left,sum,targetSum);
        count=count+dfs(root->right,sum,targetSum);
        umpp[sum]--;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        umpp[0]=1;
        int ans=dfs(root,0,targetSum);
        return ans;
    }
};
