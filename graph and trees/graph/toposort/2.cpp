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
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        int m = supplies.size();
        unordered_set<string> st;
        for (int i = 0; i < m; i++) {
            st.insert(supplies[i]);
        }
        unordered_map<string, vector<pair<string, int>>> adjList;
        unordered_set<string> st1;
        for (int i = 0; i < n; i++) {
            st1.insert(recipes[i]);
        }
        unordered_map<string, int> indegree;
        for (int i = 0; i < n; i++) {
            vector<string> vec = ingredients[i];
            for (int j = 0; j < vec.size(); j++) {
                if (st1.find(vec[j]) != st1.end()) {
                    adjList[vec[j]].push_back({recipes[i], i});
                    indegree[recipes[i]]++;
                }
            }
        }
        // TopoSort
        queue<pair<string, int>> q;
        for (int i = 0; i < n; i++) {
            if (indegree.find(recipes[i]) == indegree.end()) {
                q.push({recipes[i], i});
            }
        }
        vector<string> ans;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            string start = it.first;
            int ind = it.second;
            vector<string> vec = ingredients[ind];
            bool flag = true;
            for (int i = 0; i < vec.size(); i++) {
                if (st.find(vec[i]) == st.end()) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                ans.push_back(start);
                st.insert(start);
                for (auto nbr : adjList[start]) {
                    indegree[nbr.first]--;
                    if (indegree[nbr.first] == 0) {
                        q.push({nbr.first, nbr.second});
                        indegree.erase(nbr.first);
                    }
                }
            }
        }
        return ans;
    }
};
