class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> maxLeft(n,0);
         vector<int> maxRight(n,0);
        
        int mx= height[0];
        maxLeft[0]=0;
        for(int i=1;i<n;i++){
            maxLeft[i] = mx;
            mx = max(mx,height[i]);
        }
        
        maxRight[0]=mx;
        mx= height[n-1];
      
        for(int i=n-2;i>=0;i--){
            maxRight[i] = mx;
            mx = max(mx,height[i]);
        }
        
        int ans=0;
        
         for(int i=0;i<n;i++){
             ans+= max(min (maxRight[i],maxLeft[i]) - height[i],0);
             
         }
        
        
       
        return ans;
    }
};