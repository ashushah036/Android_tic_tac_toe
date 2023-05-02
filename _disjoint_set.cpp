#include<bits/stdc++.h>
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
int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.find_ult_parent(3) == ds.find_ult_parent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.find_ult_parent(3) == ds.find_ult_parent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}
