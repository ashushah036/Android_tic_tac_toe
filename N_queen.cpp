#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void func(int col,int n,vector<string>&board,vector<vector<string>>&ans,vector<int>&hsh_sw,vector<int>&hsh_s,vector<int>&hsh_nw){
        if(col==n){
            ans.push_back(board);
        }
        for(int row=0;row<n;row++){
            if((hsh_nw[n-1+row-col]!=1)&&(hsh_s[row]!=1)&&(hsh_sw[row+col]!=1)){
                hsh_nw[n-1+row-col]=1;
                hsh_s[row]=1;
                hsh_sw[row+col]=1;
                board[row][col]='Q';
                func(col+1,n,board,ans,hsh_sw,hsh_s,hsh_nw);
                hsh_nw[n-1+row-col]=0;
                hsh_s[row]=0;
                hsh_sw[row+col]=0;
                board[row][col]='.';               
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,"");
        vector<vector<string>>ans;
        vector<int>hsh_sw(2*n-1,0);
        vector<int>hsh_s(n,0);
        vector<int>hsh_nw(2*n-1);
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i].push_back('.');
            }
        }
        func(0,n,board,ans,hsh_sw,hsh_s,hsh_nw); 
        return ans;
    }
    
};


int main(){
    int n;
    cin>>n;
    vector<vector<string>> ans;
    Solution sol;
    ans =sol.solveNQueens(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl<<endl;
    }
    return 0;
}