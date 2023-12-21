class Solution {
public:
    int dp[2000];
    int solve(vector<int>& cost,int n,int i){
        
        if(i+2>=n){
            return 0;
        }
        
        int one=0;
        if (dp[i+1]!=-1){
            one = dp[i+1];
        }else {
            one = cost[i+1] + solve(cost,n,i+1);
            dp[i+1] = one;
        }
        
        int two=0;
        if (dp[i+2]!=-1){
            two = dp[i+2];
        }else {
            two = cost[i+2] + solve(cost,n,i+2);
            dp[i+2] = two;
        }
        
       
        
        return min(one,two);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int c = solve(cost,cost.size(),-1);
        return c;
    }
};