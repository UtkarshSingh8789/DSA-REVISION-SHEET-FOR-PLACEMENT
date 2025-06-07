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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long maxi=0;
        while(!q.empty()){
            int size=q.size();
            long long min_index=q.front().second;
            long long first,last;
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                TreeNode* node=it.first;
                long long curr_index=it.second-min_index;
                if(i==0){
                    first=curr_index;
                }
                if(i==size-1){
                    last=curr_index;
                }
                if(node->left){
                    q.push({node->left,2*curr_index+1});
                }
                if(node->right){
                    q.push({node->right,2*curr_index+2});
                }
            }
            maxi=max(maxi,(last-first+1));
        }
        return maxi;
    }
};