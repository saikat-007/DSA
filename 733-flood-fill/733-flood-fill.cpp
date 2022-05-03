class Solution {
public:
    bool isValid(int i,int j,int m,int n,vector<vector<int>>& image,int color)
    {
        if(i >= 0 && i < m && j >= 0 && j < n && image[i][j] == color)
            return true;
        
        return false;
    }
    
    void dfs(int i,int j,int m,int n,vector<vector<int>>& image,int color,int nc)
    {
        image[i][j] = nc;
        
        if(isValid(i+1,j,m,n,image,color))
            dfs(i+1,j,m,n,image,color,nc);
        
        if(isValid(i,j+1,m,n,image,color))
            dfs(i,j+1,m,n,image,color,nc);
        
        if(isValid(i-1,j,m,n,image,color))
            dfs(i-1,j,m,n,image,color,nc);
        
        if(isValid(i,j-1,m,n,image,color))
            dfs(i,j-1,m,n,image,color,nc);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int m = image.size();
        int n = image[0].size();
        
        int color = image[sr][sc];
        if(color == newColor)
            return image;
        
        dfs(sr , sc , m , n , image , color , newColor);
        
        return image;
    }
};