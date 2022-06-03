class NumMatrix {
public:
    vector<vector<int>>res;
    NumMatrix(vector<vector<int>>& matrix)
    {
        res = matrix;
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            for(int j = 1 ; j < matrix[0].size() ; j++)
                res[i][j]+=res[i][j-1];
        }
        
        for(int i = 1 ; i < matrix.size() ; i++)
        {
            for(int j = 0 ; j < matrix[0].size() ; j++)
                res[i][j]+=res[i-1][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int total = res[row2][col2];
        int extra = (row1!=0 ? res[row1-1][col2] : 0) + (col1!= 0 ? res[row2][col1 - 1] : 0) - (row1!=0 && col1!=0 ? res[row1-1][col1-1] : 0);
        
        return total - extra;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMa
 trix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */