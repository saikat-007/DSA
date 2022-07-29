class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int freq[10] = {0};
        int n = guess.size();
        int cows = 0 , bulls = 0;
        
        for(auto it : secret)
        {
            freq[it - '0']++;
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            if(guess[i] == secret[i])    
            {
                bulls++;
                freq[guess[i] - '0']--;
            }
        }
        
        
        for(int i = 0 ; i < n ; i++)
        {
            if(guess[i] != secret[i]  && freq[guess[i] - '0'] > 0)
            {
                cows++;
                freq[guess[i] - '0']--;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};