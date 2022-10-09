/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int>elements;
        vector<int>ans;
        ListNode *p = head;
        
        while(p != NULL)
        {
            elements.push_back(p->val);
            p = p -> next;
        }
        
        stack<int>stk;
        int n = elements.size();
        
        stk.push(elements[n-1]);
        ans.push_back(0);
        
        for(int i = n-2 ; i >= 0 ; i--)
        {
            while(!stk.empty() && stk.top() <= elements[i])
                stk.pop();
            
            int res = stk.empty() ? 0 : stk.top();
            ans.push_back(res);
            stk.push(elements[i]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};