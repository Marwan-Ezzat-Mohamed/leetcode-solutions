class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        vector<int> mp (k,0);

        int sum=0;
        for (auto x : nums){
            sum += x;
            mp[(sum % k +k) %k]++;
        }
    
        int ans = mp[0];
        for(auto x : mp){
            ans+=(x*(x-1))/2;
        }
        return ans;

    }
};