class Solution {
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) 
    {
        queue<pair<int,int>>q;
        int m = grid.size();
        int n = grid[0].size();
        
        int x = entrance[0];
        int y = entrance[1];
        
        q.push({x,y});
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        
        vector<vector<int>>dist(m,vector<int>(n,-1));
        
        dist[x][y] = 0;
        
        while(!q.empty())
        {
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            
            for(auto it : dir)
            {
                int nx = xx + it[0];
                int ny = yy + it[1];
                
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '.' && dist[nx][ny] == -1)
                {
                    grid[nx][ny] = '+';
                    dist[nx][ny] = 1 + dist[xx][yy];
                    q.push({nx,ny});
                    
                    if(nx == 0 || nx == m-1 || ny == 0 || ny == n-1)
                    {
                        return dist[nx][ny];
                        break;
                    }
                    
                }
            }
        }
        
        return -1;
    }
};