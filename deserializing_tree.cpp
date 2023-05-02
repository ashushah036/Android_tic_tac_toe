#include<bits/stdc++.h>
using namespace std;
int main(){
string s="1,2,3,4,5";
stringstream st(s);
string str;
int t=4;
while(t--){
getline(st,str,',');
cout<<str<<"  ";
}

}