class Solution {
public:
    int parent[26];
    
    int findparent(int node)
    {
        if(parent[node] == node)    
            return node;
        
        else
            return parent[node] = findparent(parent[node]);
    }
    
    bool equationsPossible(vector<string>& equations)
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            parent[i] = i;
        }
        
        for(auto element : equations)
        {
            if(element[1] == '=')
            {
                parent[findparent(element[0]-'a')]  = findparent(element[3] - 'a');
            }
        }
        
        for(auto element : equations)
        {
            if(element[1] == '!')
            {
                if(findparent(element[0]-'a')  == findparent(element[3] - 'a') )
                    return false;
            }
        }
        
        return true;
    }
};