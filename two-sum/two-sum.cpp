class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {       
        vector<int>ans;
        bool f=false;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((target-nums[i])==nums[j]){
                    ans.push_back(i);
                    ans.push_back(j);
                    f=true;
                }
            }
            if(f==true)
                break;
        }
        return ans;
    }
};
