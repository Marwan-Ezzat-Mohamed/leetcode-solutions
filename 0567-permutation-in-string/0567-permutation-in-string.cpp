
 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        unordered_map<int,int>mp,mp2;
        for(auto x : s1){
            mp[x-'a']++;
        }
        
        for(int i=0;i<s1.size();i++){
            mp2[s2[i]-'a']++;
        }
        
        int l = 0,r=s1.size()-1;
        while(r>=l and r<s2.size()){
            if(l!=0){
                mp2[s2[r]-'a']++;
            }
            bool valid = true;
            for(auto kvp : mp){
                int key = kvp.first;
                int val = kvp.second;
                if (mp2[key]!=val){
                    valid = false;
                    break;
                }
            }
            if (valid){
                return true;
            }
            mp2[s2[l++]-'a']--;
            r++;
         
        }
        
        return false;
    }
};