class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>v(60,0);
        int count=0;
        for(int i=0;i<time.size();i++)
        {
            int rem=time[i]%60;
            if(rem==0)
                count+=v[0];
            
            else
                count+=v[60-rem];
            
            v[rem]++;
        }
        return count;
    }
};
