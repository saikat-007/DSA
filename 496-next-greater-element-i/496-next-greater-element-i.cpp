class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int>result;
        stack<int>stk;
        unordered_map<int,int>mp;
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        stk.push(nums2[n2-1]);
        mp[nums2[n2-1]] = -1;
        
        for(int i = n2-2 ; i >= 0 ; i--)
        {
            while(!stk.empty() && stk.top() < nums2[i])
                stk.pop();
            
            int res = (stk.empty()) ? -1 : stk.top();
            mp[nums2[i]] = res;
            stk.push(nums2[i]);
        }
        
        for(auto i : nums1)
        {
            result.push_back(mp[i]);
        }
        
        return result;
    }
};