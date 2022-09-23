class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> m;
        for(auto x : strs)
        {
            string s = x;
            sort(s.begin(), s.end());
            m[s].push_back(x);
        }
        
        vector<vector<string>>fans;
        for (auto x: m){
            fans.push_back(x.second);
        }
        
        return fans;
            
    }
};