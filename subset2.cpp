#include <bits/stdc++.h>
using namespace std;
class Solution {
public: void func(int idx, vector<int> &ds,vector<int>&nums,vector<vector<int>>&ans){
   ans.push_back(ds);
//    if(idx==nums.size()){
//     return;
//    }
   for(int i=idx;i<nums.size();i++){
if((i!=idx)&&(nums[i]==nums[i-1]) ){
        continue;
    }
    ds.push_back(nums[i]);
    func(i+1,ds,nums,ans);
    ds.pop_back();

}
}

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        func(0,ds,nums,ans);
        return ans;
    }
};
int main(){
vector<int> nums;
int n;
cin>>n;
for(int i=0;i<n;i++){
    int x;
    nums.push_back(x);
}
  Solution ob;
  ob.subsetsWithDup(nums);
    return 0;
}