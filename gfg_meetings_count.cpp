#include <bits/stdc++.h>
using namespace std;
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        map <int,int> m;
        for(int i=0;i<n;i++){
            m[start[i]]=end[i];
        }
         for(int i=0;i<n;i++){
           if ( m[start[i]]>=m[start[i+1]]){
               m.erase(i);
           }
        }
        int k=m.size();
    return k;
    }
int main(){
    int n;
    cin>>n;
    int start[n],end[n];
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    for(int i=0;i<n;i++){
        cin>>end[i];
    }    
    int k=maxMeetings(start,end,n);
    cout<<k<<endl;
    return 0;
    
}