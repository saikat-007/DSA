class Solution {
public:
    int majorityElement(vector<int>& n) {
        
        //using Moore's Voting algo
        
        int res=0,count=1;
        
        // This loop is to find that number whose probability of becoming majority is maximum
       for(int i=0;i<n.size();i++)
       {
           if(n[res] == n[i])
               count++;
           
           else
               count--;
           
           if(count == 0)
           {
               res=i;
               count=1;
           }
       }
        
        //This loop is to check if our most probable element is really majority or not?
        
        count=0;
        
        for(int i=0;i<n.size();i++)
        {
            if(n[i] == n[res])
                count++;
        }
        if(count <= n.size()/2)
            return -1;
        else
            return n[res];
    }
};