class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // revisit this problem as i solved it using hints
        int l = 0 ,r =nums.size()-1;
        
        int mostLeft = nums[l],mostRight=nums[r];
        int m;
        while(l<=r){
            m = (l+r)>>1;
            if (target==nums[m])return m;
            if(nums[l]<=nums[m]){
                //we are in the left sorted portion
                if (target > nums[m] or target < nums[l]){
                    // we need to move to the right
                    l = m + 1;
                }
                else{
                    r = m - 1;
                }
            }else {
                //we are in the right sorted portion 
                 if (target < nums[m] or target > nums[r]){
                    // we need to move to the right
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};