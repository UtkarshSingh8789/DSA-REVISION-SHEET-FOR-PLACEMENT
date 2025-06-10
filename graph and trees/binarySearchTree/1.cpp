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

//APPROCH-1

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            return new TreeNode(val);
        }
        TreeNode* curr=root;
        while(true){
            if(curr->val<val){
                if(curr->right!=NULL){
                    curr=curr->right;
                }
                else{
                    curr->right=new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left!=NULL){
                    curr=curr->left;
                }
                else{
                    curr->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

//APPROCH-2

class Solution {
public:
    TreeNode* dfs(TreeNode* root,int val){
        if(root==NULL){
            return new TreeNode(val);
        }
        if(root->val>val){
            root->left=dfs(root->left,val);
        }
        else{
            root->right=dfs(root->right,val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ans=dfs(root,val);
        return ans;
    }
};