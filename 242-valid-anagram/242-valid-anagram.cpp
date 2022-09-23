class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size())return false;
        
        map<char,int>m;
        for(auto x:s)
        {
            m[x]++;
        }
        
         for(auto x:t)
        {
             if(m[x]<=0)
             {
                 return false;
             }
            m[x]--;
        }
        return true;
    }
};