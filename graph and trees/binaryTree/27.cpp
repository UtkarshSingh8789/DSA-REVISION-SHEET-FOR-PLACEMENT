// QUESTION-> you have given a binary tree you have to find the maximum path distance between any two leaf nodes;
// you have to build the graph from scratch then you have to solve the question;

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

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        this->val=x;
        this->left=NULL;
        this->right=NULL;
    }
};
class Tree{
    public:
    int ans=-INT_MIN;
    TreeNode* buildTree(){
        int ele;
        cout<<"enter the root Node";
        cin>>ele;
        if(ele==-1) return NULL;
        TreeNode* root= new TreeNode(ele);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int leftVal;
            cout<<"enter the left child of node "<<it->val<<endl;
            cin>>leftVal;
            if(leftVal!=-1){
                it->left= new TreeNode(leftVal);
                q.push(it->left);
            }
            int rightVal;
            cout<<"enter the right child of node "<<it->val<<endl;
            cin>>rightVal;
            if(rightVal!=-1){
                it->right= new TreeNode(rightVal);
                q.push(it->right);
            }
        }
        return root;
    }
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(root->left!=NULL && root->right!=NULL){
            ans=max(ans,left+right+root->val);
            return root->val+max(left,right);
        }
        else{
            if(root->left==NULL){
                return root->val+right;
            }
            else{
                return root->val+left;
            }
        }
    }
    int maxPathSum(TreeNode* root){
        dfs(root);
        return ans;
    }
};
int main(){
    Tree t1;
    TreeNode* root=t1.buildTree();
    int ans=t1.maxPathSum(root);
    cout<<ans<<endl;
}
