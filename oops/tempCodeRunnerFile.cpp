// UNDERSTANDING THE CONCEPT FROM BUILDING TREE FROM SCRATCH;
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
        val=x;
        left=NULL;
        right=NULL;
    }
};
class Tree{
    public:
    TreeNode* buildTree(){
        // LEVEL ORDER TRAVERSAL;
        // considering -1 input as a null;
        int rootval;
        cout<<"enter the value of node"<<endl;
        cin>>rootval;
        if(rootval==-1) return NULL;
        TreeNode* root=new TreeNode(rootval);// root will hold the address of newly allocated TreeNode;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int leftVal;
            cout<<"enter the left child of the tree"<<endl;
            cin>>leftVal;
            if(leftVal!=-1){
                it->left=new TreeNode(leftVal);
                q.push(it->left);
            }
            int rightVal;
            cout<<"enter the right child of the tree"<<endl;
            cin>>rightVal;
            if(rightVal!=-1){
                it->right=new TreeNode(rightVal);
                q.push(it->right);
            }
        }
        return root;
    }
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==0 || right==0){
            return 1+max(left,right);
        }
        return 1+min(left,right);
    }
    int minheight(TreeNode* root){
        // if(root==NULL) return 0;
        // int left=height(root->left);
        // int right=height(root->right);
        // return 1+max(left,right);
        int ans=dfs(root);
        return ans;
    }
};
int main(){
    Tree tree;
    TreeNode* root=tree.buildTree();
    int h=tree.minheight(root);
    cout << "Height of the tree is: " << h << endl;
    return 0;
}