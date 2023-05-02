#include <bits/stdc++.h>
using namespace std;


class DisjointSet{
public:
 vector<int>rank,parent,size;
 DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
 }

int find_ult_parent(int u){
    if(parent[u]==u){
        return u;
    }
    return parent[u]=find_ult_parent(parent[u]);
}
void unionByRank(int u,int v){
    int ulp_u=find_ult_parent(u);
    int ulp_v=find_ult_parent(v);
   if(ulp_u==ulp_v) return ;
   if(rank[ulp_u]<rank[ulp_v]){
        parent[ulp_u]=ulp_v;
    }
    else if(rank[ulp_u]>rank[ulp_v]){
        parent[ulp_v]=ulp_u;       
    }
    else{
    parent[ulp_u]=ulp_v;
    rank[ulp_v]++;
    }
}
void unionBySize(int u,int v){
    if(find_ult_parent(u)==find_ult_parent(v)) return ;
    int ulp_u=find_ult_parent(u);
    int ulp_v=find_ult_parent(v);
    if(size[ulp_u]==size[ulp_v]){
        parent[ulp_u]=find_ult_parent(v);
        size[ulp_v]+=size[ulp_u];
    }
    else if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else{
        parent[ulp_v]=ulp_u;  
        size[ulp_u]+=size[ulp_v];     
    }    
}

};


class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
           ds.unionBySize(u,v);
        }
long long ans=0;        
    for(int i=0;i<n;i++){
        if(ds.find_ult_parent(i)==i){
            long long sz=ds.size[i];
            long long rest=n=sz;
            ans+=(rest*sz);
        }
    } 
    ans=ans/2;
    return ans;       
    }

};