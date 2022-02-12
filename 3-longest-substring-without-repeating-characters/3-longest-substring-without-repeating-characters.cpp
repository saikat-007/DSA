class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,int>mpp;
        int l=0,r=0;
        int length=0;
        int n=s.size();
        
        while(r<n)
        {
            if(mpp.find(s[r])!=mpp.end())
            {
                l=max(mpp[s[r]]+1,l);  //if the current element is already present in the map and its previous index is greater than current index of l then we update the left pointer to (its previous index + 1) else we don't change l pointer
            }
            
            mpp[s[r]]=r; // updating the index of current element
            
            length=max(r-l+1,length); //r-l+1 is the length of the string in which there is no repeating characters
            
            r++;
        }
        return length;
    }
};