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
    // dryRun->10-(4+5+2)-3+(6+8);
    int calculate(string s) {
        int n=s.length();
        s.push_back('+');// koi operator milta hai tb humlog proces krte hai by keeping in mind of its previous sign so if we not add this then we cannot add a last num to our anser;
        stack<int> st;
        int curr_num=0;
        int ans=0;
        int prev_sign=1;
        for(int i=0;i<=n;i++){
            if(isdigit(s[i])){
                curr_num=curr_num*10+(s[i]-'0');
            }
            else if(s[i]=='+'){
                ans=ans+((prev_sign)*curr_num);
                prev_sign=1;
                curr_num=0;
            }
            else if(s[i]=='-'){
                ans=ans+((prev_sign)*curr_num);
                prev_sign=-1;
                curr_num=0;
            }
            else if(s[i]=='('){
                st.push(ans);
                st.push(prev_sign);
                ans=0;
                prev_sign=1;
                curr_num=0;
            }
            else if(s[i]==')'){
                // phle jo curr_num ko add krke braket solve krlete hai phir jo stack me hoga ushko add krlenge with sign;
                ans=ans+((prev_sign)*curr_num);
                curr_num=0;
                int stack_sign=st.top();
                st.pop();
                int stack_num=st.top();
                st.pop();
                ans=ans*stack_sign;
                ans=ans+stack_num;
            }
        }
        return ans;
    }
};