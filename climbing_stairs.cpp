#include <bits/stdc++.h>
using namespace std;
void func(int target ,vector<vector<int>> &ans,vector<int>&ds,int &cnt){
    if(target==0){
        ans.push_back(ds);
        cnt++;
        return;
    }
    if(target<0){
        return;
    }
    ds.push_back(1);
    func(target-1,ans,ds,cnt);
    ds.pop_back();
    ds.push_back(2);
    func(target-2,ans,ds,cnt);
    ds.pop_back();
}
int main(){
    vector<vector<int>> ans;
    vector<int>ds;
    int cnt=0;
    func(3,ans,ds,cnt);
// for(int i=0;i<ans.size();i++){
//     for(int j=0;j<ans[i].size();j++){
//         cout<<ans[i][j]<<" ";
//     }
//     cout<<endl;
// }
cout<<cnt<<endl;
    return 0;
}

//this code gives TL