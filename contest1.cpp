#include <bits/stdc++.h>
using namespace std;
class Solution {
public: int f(int sr_idx,int curr_i,int curr_j,vector<int>& target, vector<vector<int>>& specialRoads,vector<vector<vector<int>>>&dp){
    if(curr_i==target[0]&&curr_j==target[1]) return 0;
    if(sr_idx==specialRoads.size()) return abs(curr_i-target[0])+abs(target[1]-curr_j);
    if(dp[sr_idx][curr_i][curr_j]!=-1) return dp[sr_idx][curr_i][curr_j];
    int cost=0;
    int c1=1e9;
    int c2=1e9;
     if(sr_idx<specialRoads.size()){
     int crx=specialRoads[sr_idx][0];
    int cry=specialRoads[sr_idx][1];
    int nextx=specialRoads[sr_idx][2];
    int nexty=specialRoads[sr_idx][3];
    int cst=specialRoads[sr_idx][4];
    c1=abs(curr_i-crx)+abs(curr_j-cry)+cst+f(sr_idx,nextx,nexty,target,specialRoads,dp);       
     }

    c2=f(sr_idx+1,curr_i,curr_j,target,specialRoads,dp);
    cost=min(c1,c2);
    return dp[sr_idx][curr_i][curr_j]=cost;
}
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
       vector<vector<vector<int>>>dp(specialRoads.size()+1,vector<vector<int>>(target[0],vector<int>(target[1],-1)));
        return f(0,start[0],start[1],target,specialRoads,dp);
    }
};