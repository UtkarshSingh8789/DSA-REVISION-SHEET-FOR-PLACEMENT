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

// THEORY:
// 🧱 What is a struct?
// A struct is a user-defined data type that groups variables under one name.
// Used here to define a binary tree node.

// 💡 Why use a struct?
// To create a node that stores:
// val: node’s value
// left & right: pointers to children

//NOTE:
// You can also use a class here — in C++, both work similarly, except:
// struct: members are public by default
// class: members are private by default
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){  // constructor:- a special function that automaticall run when an object is created;
        val=x;
        left=NULL;
        right=NULL;
    }
};
// class TreeNode{
//     public:
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x){
//         val=x;
//         left=NULL;
//         right=NULL;
//     }
// };
class Tree{
    public:// data and methods accessible to everyone;
    TreeNode* buildTree(){
        // LEVEL ORDER TRAVERSAL;
        // considering -1 input as a null;
        int rootval;
        cout<<"enter the value of node"<<endl;
        cin>>rootval;
        if(rootval==-1) return NULL;
        TreeNode* root=new TreeNode(rootval);// root will hold the address of newly allocated TreeNode;
        // we allocate the memory on heap not at stack;
        // Unlike stack memory (which is automatically cleaned up when a function ends), heap memory stays until you delete it.
        // if we donot delete the memory then this can lead to memory leak, especially if your tree becomes large or this code runs multiple times in a long-running system (e.g., a server or online judge).
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int leftVal;
            cout<<"enter the left child of the node "<<it->val<<endl;
            cin>>leftVal;
            if(leftVal!=-1){
                it->left=new TreeNode(leftVal);
                q.push(it->left);
            }
            int rightVal;
            cout<<"enter the right child of the node "<<it->val<<endl;
            cin>>rightVal;
            if(rightVal!=-1){
                it->right=new TreeNode(rightVal);
                q.push(it->right);
            }
        }
        return root;
    }
    int minheight(TreeNode* root){
        int ans=dfs(root);
        return ans;
    }
    void freeTree(TreeNode* root){
        if(root==NULL) return;
        freeTree(root->left);
        freeTree(root->right);
        delete root; // free heap memory,avoids memory leak; without this your code will leak memory everytime it runs;
    }
    private: // data and methods are accessible inside class;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==0 || right==0){
            return 1+max(left,right);
        }
        return 1+min(left,right);
    }
};
int main(){
    Tree tree;
    TreeNode* root=tree.buildTree();
    int h=tree.minheight(root);
    cout << "Height of the tree is: " << h << endl;
    tree.freeTree(root);
    return 0;
}