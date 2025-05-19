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
};