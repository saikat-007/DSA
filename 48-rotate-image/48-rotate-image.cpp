class Solution {
public:
    void rotate(vector<vector<int>>& mat)
    {
        int n=mat.size();
        vector<vector<int>>trans(n,vector<int>(n)); // Initializing a trans matrix of n X n;
        
        // Reversing columns
        
        for(int i=0;i<n;i++)
        {
            int low=0,high=n-1;
            while(low < high)
            {
                int temp=mat[low][i];
                mat[low][i]=mat[high][i];
                mat[high][i]=temp;
                
                low++;
                high--;
            }
        }
        
        // Transpose
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                trans[i][j]=mat[j][i];
            }
        }
        
        //Copying elements of trans matrix to matrix mat
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[i][j]=trans[i][j];
            }
        }
    }
};