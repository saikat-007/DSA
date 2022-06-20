class Solution {
public:
    bool isvalid (int i , int j , int m , int n , vector<vector<int>>& board)
    {
        if(i >= 0 && j >= 0 && i < m && j < n && board[i][j] == 0)
            return true;
        
        return false;
    }
    
    void dfs(int i , int j , int m , int n , vector<vector<int>>& board)
    {
        board[i][j] = 1;
        
        if(isvalid(i+1,j,m,n,board))
            dfs(i+1,j,m,n,board);
        
        if(isvalid(i,j+1,m,n,board))
            dfs(i,j+1,m,n,board);
        
        if(isvalid(i-1,j,m,n,board))
            dfs(i-1,j,m,n,board);
        
        if(isvalid(i,j-1,m,n,board))
            dfs(i,j-1,m,n,board);
    }
    
    int closedIsland(vector<vector<int>>& board)
    {
        int m = board.size() ;
        int n = board[0].size();
        int count = 0;
        
        for(int i = 0 ; i < m ; i++)
        {
            int j = 0;
            if(board[i][j] == 0)
                dfs(i,j,m,n,board);
            
            j = n-1;
            if(board[i][j] == 0)
                dfs(i,j,m,n,board);
            
        }
        
        for(int j = 0 ; j < n ; j++)
        {
           int i = 0;
            if(board[i][j] == 0)
                dfs(i,j,m,n,board);
            
            i = m-1;
            if(board[i][j] == 0)
                dfs(i,j,m,n,board);
        }
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(board[i][j] == 0)
                {
                    count++;
                    dfs(i,j,m,n,board);
                }
            }
        }  
        
        return count;
    }
};