class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int row = mat.size();
        int col = mat[0].size();
        
        if(row == 0)
            return mat;
        
        queue<pair<int,int>>q;
        
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                }
                
                else
                    mat[i][j] = INT_MAX;
            }
        }
        
        int dir[4][2] = {{-1,0} , {1,0} , {0,-1} , {0,1}};
        
        while(!q.empty())
        {
            pair<int,int>curr = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int r = curr.first + dir[i][0];
                int c = curr.second + dir[i][1];
                
                if(r >= 0 && c >= 0 && r < row && c < col)
                {
                    if(mat[r][c] > mat[curr.first][curr.second] + 1)
                    {
                        mat[r][c] = mat[curr.first][curr.second] + 1;
                        q.push({r,c});
                    }
                }
            }
        }
        
        return mat;
    }
};