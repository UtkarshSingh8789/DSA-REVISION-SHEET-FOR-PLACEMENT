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
// Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?
//YES- this is the solution

class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushAll(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    int next() {
        auto it=st.top();
        st.pop();
        pushAll(it->right);
        return it->val;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        return false;
    }
};