class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r =1,ans=0,sz= prices.size();
        while(l!=r and r>l and r<sz){
            if (prices[l]>prices[r]){
                l=r;
                r++;
            }
            
            else{
                ans= max(ans,prices[r]-prices[l]);
                r++;
            }
            
        }
        return ans;
    }
};