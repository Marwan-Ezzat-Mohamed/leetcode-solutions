class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size()-1;
        int s =0 ;
        int e = n ;
        while(s < e)
        {
           int mid = s + (e - s) / 2;
            
            if (nums[mid]>nums[e])
            {
                s = mid +1;
                
            }else { 
                e  = mid ;
            }
        }
        return nums[s];
    }
};