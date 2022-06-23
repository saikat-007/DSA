class Solution {
public:
    bool isvalid(int i,int j,int m,int n,vector<vector<int>>& grid)
    {
        if(i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == 1)
            return true;
        
        return false;
    }
    
    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid)
    {
        grid[i][j] = 0;
        
        if(isvalid(i+1,j,m,n,grid))
            dfs(i+1,j,m,n,grid);
        
        if(isvalid(i,j+1,m,n,grid))
            dfs(i,j+1,m,n,grid);
        
        if(isvalid(i-1,j,m,n,grid))
            dfs(i-1,j,m,n,grid);
        
        if(isvalid(i,j-1,m,n,grid))
            dfs(i,j-1,m,n,grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0 ; i < m ; i++)
        {
            int j = 0;
            if(grid[i][j] == 1)
                dfs(i,j,m,n,grid);
            
            j = n-1;
            if(grid[i][j] == 1)
                dfs(i,j,m,n,grid);
        }
        
        for(int j = 0 ; j < n ; j++)
        {
            int i = 0;
            if(grid[i][j] == 1)
                dfs(i,j,m,n,grid);
            
            i = m-1;
            if(grid[i][j] == 1)
                dfs(i,j,m,n,grid);
        }
        
        int count = 0;
        for(int i = 1 ; i < m-1 ; i++)
        {
            for(int j = 1 ; j < n-1 ; j++)
            {
                if(grid[i][j] == 1)
                    count++;
            }
        }
        
        return count;
    }
};