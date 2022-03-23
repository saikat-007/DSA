class Solution {
public:
    int sum_of_squares(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int a = n%10;
            sum += a*a;
            n=n/10;
        }
        
        return sum;
    }
    
    bool isHappy(int n)
    {
        if(n <= 0)
            return false;
        
        unordered_set<int>container;
        while(container.find(n) == container.end())
        {
            container.insert(n);
            n = sum_of_squares(n);
            
            if(n == 1)
                return true;
        }
        
        return false;
    }
};