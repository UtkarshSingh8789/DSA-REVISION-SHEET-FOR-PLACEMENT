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
struct Node{
    bool flag=false;
    Node* links[26];
    string word="";
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(string& word){
        flag=true;
        this->word=word;
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string& word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                Node* new_node=new Node();
                node->put(word[i],new_node);
            }
            node=node->get(word[i]);
        }
        node->setEnd(word);
    }
};
class Solution {
public:
    int m;
    int n;
    vector<vector<bool>> visited;
    void dfs(int x,int y,Node* node,vector<vector<char>>& board,vector<string>& ans){
        visited[x][y]=true;
        Node* next_node=node->get(board[x][y]);
        if(next_node->flag==true){
            ans.push_back(next_node->word);
            next_node->flag=false;
        }
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if(new_x>=0 && new_x<m && new_y>=0 && new_y<n){
                if(!visited[new_x][new_y] && next_node->containsKey(board[new_x][new_y])){
                    dfs(new_x,new_y,next_node,board,ans);
                }
            }
        }
        visited[x][y]=false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size();
        n=board[0].size();
        int size=words.size();
        visited.resize(m,vector<bool>(n,false));
        Trie t;
        for(int i=0;i<size;i++){
            t.insert(words[i]);
        }
        vector<string> ans;
        Node* root=t.root;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(root->containsKey(board[i][j])){
                    dfs(i,j,root,board,ans);
                }
            }
        }
        return ans;
    }
};