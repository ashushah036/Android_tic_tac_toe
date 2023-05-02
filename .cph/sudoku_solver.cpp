#include <bits/stdc++.h>
using namespace std;
class Solution {
public: bool isvalid(vector<vector<char>>& board,int row ,int col,char c){
    for(int i=0;i<9;i++){
        if((board[(3*(row/3))+(i/3)][(3*(col/3))+(i%3)])==c){
            return false;
        }
        if(board[row][i]==c){
            return false;
        }
        if(board[i][col]==c){
            return false;
        } 
    }
    return true;       
}
public: bool fill(vector<vector<char>>& board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]=='.'){
                for(char c='1';c<='9';c++){

                   if(isvalid(board,i,j,c)){
                    board[i][j]=c;
                    if(fill(board)==true){
                        return true;
                    }
                    else{
                        board[i][j]='.';
                    }                   
                   } 
                }
                   return false;
            }
        }
    }
           return true;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        fill(board);
    }
};
int main(){
    vector<vector<char>> board;
    for(int i=0;i<9;i++){
        vector<char> cv;
        for(int j=0;j<9;j++){
            char x;
            cin>>x;
            cv.push_back(x);
        }
        board.push_back(cv);
    }
    Solution sol;
    sol.solveSudoku(board);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}