#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    public: void func(int idx, vector<int> &ds,vector<int>&candidates,vector<vector<int>>&ans,int target){
   
        if(target==0){
        ans.push_back(ds);            
        }
//    if(idx==nums.size()){
//     return;
//    }
   for(int i=idx;i<candidates.size();i++){
    if(i!=idx&&candidates[i-1]==candidates[i]){
        continue;
    }
       if(candidates[i]>target){
           break;
       }
    ds.push_back(candidates[i]);
    func(i+1,ds,candidates,ans,target-candidates[i]);
    ds.pop_back();
   }

}
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        func(0,ds,candidates,ans,target);
        return ans;
    }
};
int main(){
    
}