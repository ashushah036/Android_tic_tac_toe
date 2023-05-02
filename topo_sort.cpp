#include<bits/stdc++.h>
using namespace std;
	vector<int> topoSort(int &V, vector<int> adj[]) 
	{
	   vector<int>indegree(V,0);
	     for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
      queue<int>q;
      vector<int>topo;
      for(int i=0;i<V;i++){
          if(indegree[i]==0){
              q.push(i);
          }
      }
      while(!q.empty()){
          int node=q.front();
          topo.push_back(node);
          q.pop();
          for(auto it:adj[node]){
              indegree[it]--;
              if(indegree[it]==0) q.push(it);
          }
      }
      return topo;
	}
int main(){
    int edge;
    cin>>edge;
    vector<vector<int>> richer(edge,vector<int>(2,0));
    for(int i=0;i<edge;i++){
        for(int j=0;j<2;j++){
            int x;
            cin>>x;
            richer[i][j]=x;
        }
    }
    int no;
    cin>>no;
    vector<int>quiet(no,0);
    for(int i=0;i<no;i++){
        int temp;
        cin>>temp;
        quiet[i]=temp;
    }
        int n=quiet.size();
        vector<int> adj[n];
        for(int i=0;i<richer.size();i++){
            int u=richer[i][0];
            int v=richer[i][1];
            adj[u].push_back(v);
        }
        vector<int> topo_seq=topoSort(n,adj);
        for(auto it:topo_seq) cout<<it<<" ";
        cout<<endl;
}