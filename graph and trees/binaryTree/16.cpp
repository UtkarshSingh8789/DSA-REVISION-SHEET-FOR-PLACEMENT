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
    int n;
    TreeNode* dfs(int& i,int depth,string& traversal){
        if(i>=n) return NULL;
        int j=i;
        while(j<n && traversal[j]=='-'){
            j++;
        }
        int dash=j-i;
        if(dash!=depth) return NULL;
        i=j;
        int num=0;
        while(i<n && isdigit(traversal[i])){
            num=(num*10)+(traversal[i]-'0');
            i++;
        }
        TreeNode* root=new TreeNode(num);
        root->left=dfs(i,depth+1,traversal);
        root->right=dfs(i,depth+1,traversal);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        n=traversal.length();
        int i=0;
        int depth=0;
        return dfs(i,depth,traversal);
    }
};