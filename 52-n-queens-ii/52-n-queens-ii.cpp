class Solution {
    bool isSafe(int row,int col,vector<string>& board){
        //row traversal
        for(int i=row;i>=0;i--){
            if(board[i][col]=='Q')
                return false;
        }
        //diagonal left
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q')
                return false;
        }
        //diagonal right
        for(int i=row,j=col;i>=0&&j<board.size();i--,j++){
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
    void helper(int row,int& ans,vector<string>& board){
        if(row==board.size()){
            ans++;
            return;
        }
        /*
        put the queen 
        call for other rows
        backtrack i.e remove the queen
        */
        for(int j=0;j<board.size();j++){
            if(isSafe(row,j,board)){
                board[row][j]='Q';
                helper(row+1,ans,board);
                board[row][j]='.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        int ans=0;
        helper(0,ans,board);
        return ans;
    }
};