class Solution {
public:
    int minMoves(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int minNum = nums[0];
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        return sum-minNum*n;
    }
};

/*
let's define sum as the sum of all the numbers, before any moves; minNum as the min number int the list; n is the length of the list;

After, say m moves, we get all the numbers as x , and we will get the following equation

sum + m * (n - 1) = x * n

and actually, x = minNum + m

why x = minNum + m
our goal is :increment minNum to be equal to maxNum

No matter how many add operations are executed,the goal won't change.
Every time we do the add operation,the min number in the array must participate in.
After an add operation,the minNum is still the min number
So the minNum participate in every add operation
So x = minNum + m

*/