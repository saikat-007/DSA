class Solution {
public:
    int largestRectangleArea(vector<int>& height)
    {
        int n = height.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>stk;
        
        
        // for finding left smaller element 
        
        for(int i=0;i<n;i++)
        {
            while(stk.empty()==false && height[stk.top()]>=height[i])
            {
                stk.pop();
            }
            
            if(stk.empty())
                left[i]=0;
            else
                left[i] = stk.top()+1;
            
            stk.push(i);
        }
        
        //emptying stack stk to reuse
        
        while(stk.empty()!=true)
        {
            stk.pop();
        }
        
        // finding right smaller
        
        for(int i=n-1;i>=0;i--)
        {
            while(stk.empty()==false && height[stk.top()]>=height[i])
            {
                stk.pop();
            }
            
            if(stk.empty())
                right[i]=n-1;
            else
                right[i]=stk.top()-1;
            
            stk.push(i);
        }
        
        //finding area
        int max_area=0;
        for(int i=0;i<n;i++)
        {
            max_area=max(max_area,(right[i]-left[i] + 1)*height[i]);
        }
        
        return max_area;
    }
};

// for(int i=0;i<n;i++)
//         {
//             while(stk.empty()==false && height[stk.top()] >= height[i])
//             {
//                 stk.pop();
//             }
//             if(stk.empty()==true)left[i]=0;
//             else left[i]=stk.top()+1;
//             stk.push(i);
//         }
        
//         while(!stk.empty()) // for reusing the stack
//             stk.pop();
        
//         for(int i=n-1;i>=0;i--)
//         {
//             while(!stk.empty() && height[stk.top()]>=height[i])
//             {
//                 stk.pop();
//             }
//             if(stk.empty()) right[i]=n-1;
//             else right[i]=stk.top()-1;
//             stk.push(i);
//         }
        
//         int max_area=0;
//         for(int i=0;i<n;i++)
//         {
//             max_area=max(max_area,(height[i]*(right[i]-left[i]+1)));
//         }
//         return max_area;