class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        if (r*c != mat.size()*mat[0].size())
        {
            return mat;
        }
        
        else
        {
            vector<int>res;
            for(int i=0;i<mat.size();i++)
            {
                for(int j=0;j<mat[i].size();j++)
                {
                    res.push_back(mat[i][j]);
                }
            }
            
            
            int k=0;
            vector<vector<int>>v;
            for(int i=0;i<r;i++)
            {
                vector<int>temp;
                for(int j=0;j<c;j++)
                {
                    temp.push_back(res[k]);
                    k++;
                }
                v.push_back(temp);
            }
             return v;
        }
       
    }
};