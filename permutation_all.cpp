#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    public:
    void func(vector<int>&v,vector<int>&tick,vector<int>&nums,vector<vector<int>> &ans){
            if(v.size()==nums.size()){
                ans.push_back(v);
            }        
        for(int i=0;i<nums.size();i++){
            if(tick[i]!=0){
                continue;
            }
            tick[i]=1;
            v.push_back(nums[i]);
            func(v,tick,nums,ans);
            v.pop_back();  
            tick[i]=0;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>v;
        vector<int>tick(nums.size(),0);
        vector<vector<int>>ans;
        func(v,tick,nums,ans);
        return ans;
    }
};

int main(){

    return 0;
}