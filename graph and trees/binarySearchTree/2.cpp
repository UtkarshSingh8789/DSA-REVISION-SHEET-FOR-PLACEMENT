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
    TreeNode* findRightMostNode(TreeNode* root){
        if(root->right==NULL) return root;
        return findRightMostNode(root->right);
    }

    TreeNode* helper(TreeNode* node){
        if(node->left==NULL){
            return node->right;
        }
        if(node->right==NULL){
            return node->left;
        }
        TreeNode* rightChild=node->right;
        TreeNode* curr=findRightMostNode(node->left);
        curr->right=rightChild;
        return node->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            return helper(root);
        }
        TreeNode* curr=root;
        while(curr!=NULL){
            if(key<curr->val){
                if(curr->left!=NULL && curr->left->val==key){
                    curr->left=helper(curr->left);
                    break;
                }
                else{
                    curr=curr->left;
                }
            }
            else{
                if(curr->right!=NULL && curr->right->val==key){
                    curr->right=helper(curr->right);
                    break;
                }
                else{
                    curr=curr->right;
                }
            }
        }
        return root;
    }
};