#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    unordered_map<char,vector<char>> adjList;
    unordered_map<char,int> indegree;
    void complete(string s1,string s2){
        int n1=s1.length();
        int n2=s2.length();
        if(s1.size()>s2.size() && s1.substr(0,s2.size()) == s2) {
            indegree.clear();
            return;
        }
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(s1[i]!=s2[j]){
                adjList[s1[i]].push_back(s2[i]);
                indegree[s2[j]]++;
                break;
            }
            i++;
            j++;
        }
    }
    string findOrder(vector<string> &words) {
        // code here
        int n=words.size();
        for(int i=0;i<n;i++){
            string s=words[i];
            for(int j=0;j<s.length();j++){
                indegree[s[j]]=0;
            }
        }
        for(int i=0;i<n-1;i++){
            complete(words[i],words[i+1]);
            if(indegree.empty()) return "";
        }
        string ans;
        queue<char> q;
        for(auto it:indegree){
            if(it.second==0){
                q.push(it.first);
                ans.push_back(it.first);
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto nbr:adjList[it]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                    ans.push_back(nbr);
                }
            }
        }
        if(ans.size()==indegree.size()) return ans;
        return "";
    }
};
