class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        if(mat.size() == 0)
            return false;
        
        int m=mat.size();
        int n=mat[0].size();
        int low=0,high=m*n-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(mat[mid/n][mid%n] == target)
                return true;
            
            else if(mat[mid/n][mid%n] < target)
                low=mid+1;
            
            else
                high=mid-1;
        }
        return false;
    }
};