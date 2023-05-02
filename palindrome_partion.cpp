#include <bits/stdc++.h>
using namespace std;
class Solution {
public :int checkpalindrome(string s) {
    int flag=1;
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-1-i]){
            flag=0;
            break;
        }
    }
    return flag;
}
public: void func(int idx,string s,vector<vector<string>>&ans,vector<string>&tillnow){
    if(idx==s.size()){
        ans.push_back(tillnow);
        return;
    }
    for(int i=idx;i<(s.size());i++){
        string str=s.substr(idx,idx+1-i);
        if(checkpalindrome(str)){
            tillnow.push_back(str);
        func(i+1,s,ans,tillnow);
        tillnow.pop_back();            
        }

    }
}

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>tillnow;
        func(0,s,ans,tillnow);
        return ans;

    }
};