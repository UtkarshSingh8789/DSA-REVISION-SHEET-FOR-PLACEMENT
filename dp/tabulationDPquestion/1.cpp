#include<bits/stdc++.h>
using namespace std;
//dp[i]=total number of vowels in all the substring ending at i;
class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
        return false;
    }  
    long long countVowels(string word) {
        int n=word.length();
        vector<long long> dp(n);
        if(isVowel(word[0])){
            dp[0]=1;
        }
        else if(!isVowel(word[0])){
            dp[0]=0;
        }
        for(int i=1;i<n;i++){
            if(isVowel(word[i])){
                dp[i]=1+dp[i-1]+i;
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            sum=sum+dp[i];
        }
        return sum;
    }
};
