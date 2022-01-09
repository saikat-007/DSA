class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n)
    {
        sort(n.begin(),n.end());
        vector<vector<int>>res;
        
        int i,j,k,sum=0;
        for(int i=0;i<n.size();i++)
        {
            vector<int>temp;
            int j=i+1;
            k=n.size()-1;
            sum=0-n[i];
            
            if ((i>0) && (n[i]==n[i-1])) // avoiding duplicates for i pointer
                continue;
            
            while(j<k)
            {
                if(n[j]+n[k]==sum)
                {
                    temp.push_back(n[i]);
                    temp.push_back(n[j]);
                    temp.push_back(n[k]);
                    res.push_back(temp);
                    temp.clear();
                    while (j+1<k && n[j]==n[j+1]) j++;
                    while (k-1>j && n[k]==n[k-1]) k--; //since we have skipped duplicates and are on the last occurence of those duplicates we need to update the pointers one more time to get to new values
                    j++;
                    k--;
                }
                else if(n[j]+n[k]<sum)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
            
        }
        return res;
    }
};