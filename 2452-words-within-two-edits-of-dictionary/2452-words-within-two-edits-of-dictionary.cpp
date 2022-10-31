class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d)
    {
        vector<string>ans;
        
        for(int i = 0 ; i < q.size() ; i++)
        {
            string query = q[i];
            
            for(int j = 0 ; j < d.size() ; j++)
            {
                string dict = d[j];
                int count = 0;
                
                for(int k = 0 ; k < query.size() ; k++)
                {
                    if(dict[k] != query[k])
                        count++;
                }
                
                if(count <= 2)
                {
                    ans.push_back(query);
                    break;
                }
            }
        }
        
        return ans;
    }
};