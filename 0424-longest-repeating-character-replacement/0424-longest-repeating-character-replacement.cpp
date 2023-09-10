

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int>mp;
        int l =0 , r=0;
        int n= s.size();
        bool fakes=false;
        int ans=0;
        while (l <=r and r<n){
            //if valid 
            if(!fakes)mp[s[r]]++;
            int winLen = r-l+1;
            auto pr = max_element(mp.begin(), mp.end(), [](const auto &x, const auto &y) {
                    return x.second < y.second;
           });
            int maxFreqChar = pr->second;
              bool valid = (winLen -maxFreqChar)<=k ;
             //cout<<winLen<<" "<<maxFreqChar<<" "<<l<<" "<<r<<" "<<valid<<endl;
            // cout<<mp;
            if (valid)
            {
                r++;
                fakes= false;
               
                ans = max(ans , r-l);
            }else {
              
                mp[s[l]]--;
                l++;
                fakes=true;
                
            }
        }
        
     
        
        
        return ans;
        
    }
};