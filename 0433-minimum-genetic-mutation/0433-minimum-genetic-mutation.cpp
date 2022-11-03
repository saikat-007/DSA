class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        queue<string>q;
        unordered_set<string>seen;
        
        q.push(start);
        seen.insert(start);
        
        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0 ; i < size ; i++)
            {
                string s = q.front();
                q.pop();
                
                if(s == end)
                    return steps;
                
                for(char c : "ATGC")
                {
                    for(int i = 0 ; i < s.size() ; i++)
                    {
                        string neighbour = s;
                        neighbour[i] = c;
                        
                        if(seen.count(neighbour) == 0 && find(bank.begin(),bank.end(),neighbour) != bank.end())
                        {
                            q.push(neighbour);
                            seen.insert(neighbour);
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};