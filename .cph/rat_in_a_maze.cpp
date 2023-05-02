#include <bits/stdc++.h>
using namespace std;
class Solution{
    public: void solve(int i,int j,string s,vector<string> &ans,vector<vector<int>> &mark,vector<vector<int>> &m, int n){
        if(i==n-1&&j==n-1){
            ans.push_back(s);
            return;
        }
        //DLRU order should be maintained because we want the path in 
        //box pe reh ke fxn call kar rahe and jab rasta mlha tbhi
        if(i+1<n&&mark[i+1][j]==0&&m[i+1][j]!=0){
            mark[i][j]=1;
            solve(i+1,j,s+'D',ans,mark,m,n);
            mark[i][j]=0;
        }

        if(j-1>=0&&mark[i][j-1]==0&&m[i][j-1]!=0){
            mark[i][j]=1;
            solve(i,j-1,s+'L',ans,mark,m,n);
            mark[i][j]=0;

        }
        if(j+1<n&&mark[i][j+1]==0&&m[i][j+1]!=0){
            mark[i][j]=1;
            solve(i,j+1,s+'R',ans,mark,m,n);
        }
        if(i-1>=0&&mark[i-1][j]==0&&m[i-1][j]!=0){
            mark[i][j]=1;
            solve(i-1,j,s+'U',ans,mark,m,n);
            mark[i][j]=0;

        }                        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<int>> mark;
        if(m[0][0]==0){
            return ans;
        }
        for(int i=0;i<n;i++){
            vector<int>x(n,0);
            for(int j=0;j<n;j++){
            mark.push_back(x);
            }
        }
        solve(0,0,"",ans,mark,m,n);
        return ans;
    }
};