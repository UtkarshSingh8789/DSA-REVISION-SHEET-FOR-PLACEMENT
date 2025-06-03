#include<bits/stdc++.h>
using namespace std;
//JB BHI DONO START AND END SE BARA KRNA HAI HUMLOG KO TOH HUMESA START KO ASCENDING AND END KO DESCENDING;
class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        else{
            return a[0]<b[0];
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(envelopes[i][1]>temp.back()){
                temp.push_back(envelopes[i][1]);
            }
            else{
                auto it=lower_bound(temp.begin(),temp.end(),envelopes[i][1])-temp.begin();
                temp[it]=envelopes[i][1];
            }
        }
        int ans=temp.size();
        return ans;
    }
};