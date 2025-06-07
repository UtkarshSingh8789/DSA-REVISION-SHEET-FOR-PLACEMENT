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
};// inportant we have solve this question in time complexity less than O(n) i.e O(logN^2)
class Solution {
public:
    int lh(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->left;
        }
        return count;
    }
    int rh(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->right;
        }
        return count;
    }
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int leftNodes=lh(root);
        int rightNodes=rh(root);
        if(leftNodes==rightNodes){
            return ((1<<leftNodes)-1);
        }
        int leftAns=dfs(root->left);
        int rightAns=dfs(root->right);
        return 1+leftAns+rightAns;
    }
    int countNodes(TreeNode* root) {
        // if(root==NULL){
        //     return 0;
        // }
        // int leftAns=countNodes(root->left);
        // int rightAns=countNodes(root->right);
        // return (leftAns+rightAns+1);
        
        //another solution:
        //this solution is only valid because the tree is complete trees;
        int ans=dfs(root);
        return ans;
    }
};