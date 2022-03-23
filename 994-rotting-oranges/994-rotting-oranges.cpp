class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int m , n , tot=0 , rot=0 , mins = 0 ;
        
        m = grid.size();
        n = grid[0].size();
        
        queue<pair<int,int>>box;
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) box.push({i,j});
            }
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(box.empty() == false)
        {
            int k = box.size();
            rot += k;
            while(k--)
            {
                int x,y;
                x = box.front().first;
                y = box.front().second;
                box.pop();
                
                for(int i = 0 ; i < 4 ; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1) continue;
                        
                    grid[nx][ny] = 2;
                    box.push({nx,ny});
                }
            }
            if(!box.empty()) mins++;
        }
        
        return tot == rot ? mins : -1;
    }
};