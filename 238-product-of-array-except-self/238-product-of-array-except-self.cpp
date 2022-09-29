class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=nums[0];
        int zeros=0;
        for(auto x : nums)
        {
            product = min(product,x);
            if(x==0)zeros++;
        }
        
        if(product<0)product = 1;
        else if(product >0)product = 1;
        
        
        int productNoZero=1;
        for(auto x : nums)
        {
            product *=x;
            if(x!=0)productNoZero *=x;
        }
        
        vector<int>ans;
         for(auto x : nums)
        {
            if(x==0)
            {
                if(zeros==1)
                {
                    ans.push_back(productNoZero);
                }else{
                    ans.push_back(0);
                }
                
            }else {
                ans.push_back(product/x);
            }
        }
        
        return ans;
        
    }
};