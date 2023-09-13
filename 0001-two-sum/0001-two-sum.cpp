class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int index = 1;
        for(auto x : nums){
            mp[x]= index++;
        }
        
        for(int i=0;i<nums.size();i++){
            int find= target- nums[i];
            int possibleIndex =mp[find];
            if(possibleIndex && possibleIndex!=i+1){
                return {i,possibleIndex-1};
            }
        }
        
        return {};
    }
};