class Solution {
    public:
        int n;
        bool solve(int i,string& num,vector<int>& ans){
            if(i>=n){
                if(ans.size()>=3) return true;
                return false;
            }
            int end=10;
            if(num[i]=='0') end=1;
            for(int j=1;j<=end && i+j<=n;j++){
                string s1=num.substr(i,j);
                long long n1=stoll(s1);
                if(n1>INT_MAX) return false;
                if(ans.size()>=2 && ((long long)ans[ans.size()-1]+(long long)ans[ans.size()-2])<n1) return false;
                if(ans.size()<=1 || ((long long)ans[ans.size()-1]+(long long)ans[ans.size()-2])==n1){
                    ans.push_back(n1);
                    if(solve(i+j,num,ans)==true) return true;
                    ans.pop_back();
                }
            }
            return false;
        }
        vector<int> splitIntoFibonacci(string num) {
            n=num.length();
            vector<int> ans;
            solve(0,num,ans);
            return ans;
        }
    };