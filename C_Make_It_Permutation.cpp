#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n,c,d;
    cin>>n>>c>>d;
    vector<int>v;
    set<int>st;
    unordered_map<int,int>mp,pos;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        st.insert(x);
        mp[x]++;
        v.push_back(x);
    }
sort(v.begin(),v.end());
for(int i=0;i<n;i++){
    pos[v[i]]=i;
}
    long long  min_cost=n*c;
    auto it=st.begin();
    int extra=0;
    int idx=0;
for(auto it1=st.begin();it1!=st.end();it1++){
    int num=(*it1);
    extra+=(mp[num]-1);
    long long need=num-idx-1;
    long long remove=n-pos[num]-1+extra;
    long long ct= remove*c+need*d;
    min_cost=min(min_cost,ct);
    idx++;
}
    cout<<min_cost<<endl;
}
}