class Solution {
    public int characterReplacement(String s, int k) 
    {
        int left = 0;
        int n = s.length();
        
        int max = 0;
        int count[] = new int[26];
        int maxChar = 0;
        
        for(int right = 0 ; right < n ; right++)
        {
            char c = s.charAt(right);
            count[c-'A']++;
            int windowsize = right - left + 1;
            maxChar = Math.max(maxChar , count[c-'A']);
            
            int replacecount = windowsize - maxChar;
            if(replacecount > k)
            {
                count[s.charAt(left) - 'A']--;
                left++;
            }
            
            else
                max = Math.max(max , windowsize);
        }
        
        return max;
    }
}