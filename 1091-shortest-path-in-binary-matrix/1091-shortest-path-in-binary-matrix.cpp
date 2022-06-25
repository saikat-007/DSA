class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        if(grid[0][0] == 1)    
            return -1;
        
        if(n == 1 && grid[0][0] == 0)
            return 1;
        
        int xdir[8] = {0,0,1,-1,1,1,-1,-1};
        int ydir[8] = {1,-1,0,0,1,-1,1,-1};
        
        queue <pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i = 0 ; i < 8 ; i++)
            {
                int xx = x + xdir[i];
                int yy = y + ydir[i];
                
                if(xx >= 0 && yy >= 0 && xx < n && yy < n && grid[xx][yy] == 0)
                {
                    grid[xx][yy] = grid[x][y] + 1;
                    q.push({xx,yy});
                    
                    if(xx == n-1 && yy == n-1)
                        return grid[xx][yy] + 1;
                }
            }
            
        }
        
        return -1;
    }
};