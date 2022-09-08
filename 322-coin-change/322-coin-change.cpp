// Greedy approach --> this seems to be working fine but actually its not , like the example {9,6,5,1} and target = 11 greedy fails

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount)
//     {
//         sort(coins.begin(),coins.end(),greater<int>());
        
//         int i=0;
        
//         int count=0;
        
//         while(amount>0 && i<coins.size())
//         {
//             count+=amount/coins[i];
//             amount=amount%coins[i];
//             i++;
//         }
        
//         return amount == 0?count:-1;
//     }
// };


//<--------------------------Recursive Approach ------------------------------------->

// class Solution {
// public:
//     int getCoins(vector<int>& coins , int amt , int idx)
//     {
//         if(idx == 0)
//         {
//             if(amt % coins[idx] == 0)
//                 return amt / coins[idx];
            
//             else
//                 return 1e9;
//         }
        
//         int not_take = getCoins(coins , amt , idx - 1);
//         int take = INT_MAX;
//         if(amt >= coins[idx])
//         {
//             take = 1 + getCoins(coins , amt - coins[idx] , idx);
//         }
        
//         return min(not_take , take);
//     }
    
//     int coinChange(vector<int>& coins, int amount)
//     {
//         int n = coins.size();
//         int ans = getCoins(coins , amount , n-1);
//         if(ans >= 1e9) return -1;
//         else return ans;
//     }
// };


class Solution {
public:
    int getCoins(vector<int>& coins , int amt , int idx , vector<vector<int>>&dp)
    {
        if(idx == 0)
        {
            if(amt % coins[idx] == 0)
                return amt / coins[idx];
            
            else
                return 1e9;
        }
        
        if(dp[idx][amt] != -1)
            return dp[idx][amt];
        
        int not_take = getCoins(coins , amt , idx - 1 , dp);
        int take = INT_MAX;
        if(amt >= coins[idx])
        {
            take = 1 + getCoins(coins , amt - coins[idx] , idx , dp);
        }
        
        return dp[idx][amt] = min(not_take , take);
    }
    
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>>dp(n , vector<int>(amount + 1 , -1));
        int ans = getCoins(coins , amount , n-1 ,dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};