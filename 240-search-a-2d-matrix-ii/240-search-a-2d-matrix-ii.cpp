class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target)
    {
        int r = mat.size();
        int c = mat[0].size();
        int i = 0,j = c-1;
        
        while(i < r && j >= 0)
        {
            if(mat[i][j] == target)
                return true;
            
            else if(mat[i][j] < target)
                i++;
            
            else
                j--;
        }
        return false;
    }
};