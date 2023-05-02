#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> height;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        height.push_back(x);
    }

    vector<int>dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int min_energy_till=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump=dp[i-j]+abs(height[i]-height[i-j]);
                min_energy_till=min(jump,min_energy_till);
            }
        }
        dp[i]=min_energy_till;
    }
cout<<dp[n-1];

}