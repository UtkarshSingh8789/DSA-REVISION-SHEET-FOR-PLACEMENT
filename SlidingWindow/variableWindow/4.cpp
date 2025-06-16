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

// very inportant pattern when we have to count the number of subarray and this is applied when know where the end of window can extend upto;
class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
    long long countOfSubstrings(string word, int k) {
        int n=word.size();
        vector<int> ind(n);
        int index=n;
        for(int i=n-1;i>=0;i--){
            ind[i]=index;
            if(!isVowel(word[i])){
                index=i;
            }
        }
        int i=0;
        int j=0;
        long long ans=0;
        unordered_map<char,int> umpp;
        int count=0;
        while(j<n){
            char ch=word[j];
            if(isVowel(ch)){
                umpp[ch]++;
            }
            else count++;
            while(count>k){
                char ch=word[i];
                if(isVowel(ch)){
                    umpp[ch]--;
                    if(umpp[ch]==0) umpp.erase(ch);
                }
                else{
                    count--;
                }
                i++;
            }
            while(count==k && umpp.size()==5){
                int index=ind[j];
                ans=ans+(index-j);
                if(isVowel(word[i])){
                    umpp[word[i]]--;
                    if(umpp[word[i]]==0) umpp.erase(word[i]);
                }
                else{
                    count--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};