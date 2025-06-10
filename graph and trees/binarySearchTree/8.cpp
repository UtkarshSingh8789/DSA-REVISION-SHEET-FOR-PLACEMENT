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

//BRUTE FORCE:

class Solution {
public:
    unordered_map<int,int> umpp;
    bool dfs(TreeNode* root,int k){
        if(root==NULL) return false;
        if(umpp.find(k-root->val)!=umpp.end()){
            return true;
        }
        umpp[root->val]++;
        if(dfs(root->left,k)==true) return true;
        if(dfs(root->right,k)==true) return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        bool ans=dfs(root,k);
        return ans;
    }
};

// MOST optimized way space is O(H)
class BSTIterator {
    public:
    stack<TreeNode*> st;
    bool reverse=true;
    BSTIterator(TreeNode* root,bool isreverse){
        reverse=isreverse;
        pushAll(root);
    }
    bool hasNext(){
        if(!st.empty()) return true;
        return false;
    }
    int next(){
        auto it=st.top();
        st.pop();
        if(reverse){
            pushAll(it->left);
        }
        else{
            pushAll(it->right);
        }
        return it->val;
    }
    void pushAll(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            if(reverse){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int target) {
        if(root==NULL) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==target) return true;
            if((i+j)>target){
                j=r.next();
            }
            else{
                i=l.next();
            }
        }
        return false;
    }
};