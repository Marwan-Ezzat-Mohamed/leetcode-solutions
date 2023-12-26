class Solution {
public:
    int n=0;
    int dp[200][2];
    int solve(vector<int>& nums,int i,bool tf){
        if(i>=n)return 0;
        
        if(dp[i][tf]!=-1){
            return dp[i][tf];
        }
        if (tf && i==n-1){
            dp[i][tf] = 0;
          
            return dp[i][tf];
        }
        
        int take = nums[i] + solve(nums,i+2,i==0 || tf);
        int leave = solve(nums,i+1, tf);
        dp[i][tf] = max(take,leave);
        return dp[i][tf];
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof dp);
        return solve(nums,0,false);
    }
};