class Solution {
public:
    int dfs(int m , int n , int i , int j , vector<vector<int>>& grid)
    {
        if(i >= m || j >= n  || i < 0 || j < 0 || !grid[i][j])
            return 0;
        
        grid[i][j] = 0;
        return (1 + dfs(m,n,i+1,j,grid) + dfs(m,n,i,j+1,grid) + dfs(m,n,i-1,j,grid) + dfs(m,n,i,j-1,grid));
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        int res = 0;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 1)
                    res = max(res,dfs(m,n,i,j,grid));
            }
        }
        
        return res;
    }
    
    
};