class Solution {
public:
    int maxDistance(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>>q;
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    q.push({i,j});
                }
                
                else
                    grid[i][j] = INT_MAX;
            }
        }
        
        int ans = 0;
        int dir[4][2] = {{-1,0} , {1,0} , {0,-1} , {0,1}};
        
        while(!q.empty())
        {
            pair<int,int>curr = q.front();
            q.pop();
            
            for(int i = 0 ; i < 4 ; i++)
            {
                int r = curr.first + dir[i][0];
                int c = curr.second + dir[i][1];
                
                if(r >= 0 && r < m && c >= 0 && c < n)
                {
                    if(grid[r][c] > grid[curr.first][curr.second] + 1)
                    {
                        grid[r][c] = grid[curr.first][curr.second] + 1;
                        q.push({r,c});

                        ans = max(ans , grid[r][c]);
                    }   
                }
            }
        }
        
        // cases where we only have land(ans = INT_MAX) or only have water(ans = 0)
        if (ans == INT_MAX or ans == 0) return -1;
        return ans;
    }
};