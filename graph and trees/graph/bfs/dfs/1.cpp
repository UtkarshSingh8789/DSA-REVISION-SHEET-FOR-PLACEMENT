#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string s, string e, vector<string>& wordList) {
        int n=wordList.size();
        unordered_map<string,int> umpp;
        for(int i=0;i<n;i++){
            string s=wordList[i];
            umpp[s]++;
        }
        queue<pair<string,int>> q;
        q.push({s,1});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string s=it.first;
            int count=it.second;
            if(s==e) return count;
            for(int i=0;i<s.length();i++){
                string str=s;
                for(char ch='a';ch<='z';ch++){
                    str[i]=ch;
                    if(umpp.find(str)!=umpp.end()){
                        q.push({str,count+1});
                        umpp.erase(str);
                    }
                }
            }
        }
        return 0;
    }
};//given start word ke hr ek index pe jake character ko change krenge aur agr new string map me hoga toh
// ushko queue me push krenge wth increase in count -> bfs traversal;
// isme jb map me mil jata hai to map se erase krna bhuljate hai -> common mistake;

// time complexity->
 
// O(N * L) (building hashmap) + O(N * L) (BFS)
// =>
// O(N * L)


// space complexity->

// Hashmap (umpp):
// Stores all N words.
// Space: O(N * L)
// Queue:
// At worst, all words could be in the queue at some point.
// Space: O(N * L)
// Strings in the queue and temporary variables:
// Each string uses O(L) space.
// Total: Covered by the queue and hashmap already

// O(N * L)  SPACE COMPLEXITY