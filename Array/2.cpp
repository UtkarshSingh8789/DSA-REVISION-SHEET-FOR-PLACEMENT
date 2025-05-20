#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int isThere(vector<int>& v,int val){
        int start=0;
        int end=v.size()-1;
        int ans=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(v[mid]>val){
                ans=v[mid];
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        n=s.length();
        int m=words.size();
        int ans=0;
        unordered_map<char,vector<int>> umpp;
        for(int i=0;i<n;i++){
            umpp[s[i]].push_back(i);
        }
        for(int i=0;i<m;i++){
            string s1=words[i];
            int previous=-1;
            bool flag=true;
            for(int j=0;j<s1.length();j++){
                vector<int>& v=umpp[s1[j]];
                int val=isThere(v,previous);
                if(val==n){
                    flag=false;
                    break;
                }
                else{
                    previous=val;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};