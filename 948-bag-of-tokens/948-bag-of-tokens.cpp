class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        int n = tokens.size();
        sort(tokens.begin() , tokens.end());
        int low = 0 , high = n-1;
        int score = 0;
        
        while(low <= high)
        {
            if(power >= tokens[low])
            {
                power -= tokens[low];
                score += 1;
                // max_score = max(max_score , score);
                low++;
            }
            
            else if(score && (low != high))
            {
                power += tokens[high];
                score -= 1;
                high --;
            }
            
            else
                break;
        }
        
        return score;
    }
};