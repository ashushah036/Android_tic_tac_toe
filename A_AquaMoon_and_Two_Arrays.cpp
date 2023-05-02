#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vector<int>a;
        vector<int>b;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            b.push_back(x);
        }

        vector<int>v;

        int sum=0;
        int cnt=0;

        for(int i=0;i<n;i++){
            int diff=b[i]-a[i];
            v.push_back(diff);
            sum+=diff;
            cnt+=abs(diff);
        }

        // for(int i=0;i<n;i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;

        if(sum==0){
            int i=0,j=0;
            cout<<cnt/2<<endl;#
            while(i<n && j<n){
                while(v[i]>=0) i++;
                while(v[j]<=0) j++;
                if(i<n && j<n){
                    cout<<i+1<<" "<<j+1<<endl;
                    v[i]++;
                    v[j]--;
                    if(v[i]>=0) i++;
                    if(v[j]<=0) j++;
                }
            }
        }
        else cout<<"-1"<<endl;

    }

    return 0;
}