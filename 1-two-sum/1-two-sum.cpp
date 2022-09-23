class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        
        vector<int> copy ;
        copy = nums;
        sort(copy.begin(),copy.end());
        
     
        for(int i=0;i<nums.size();i++)
        {
            int search = target - nums[i];
            if(binary_search(copy.begin(), copy.end(), search))
            {
                cout<<"found";
                vector<int> v;
                v.push_back(i);
                for(int j=0;j<nums.size();j++)
                {
                    if(nums[j]==search&&i!=j)
                    {
                        v.push_back(j);
                        break;
                    }
                }
                if(v.size()==2)
                    return v;
            }
            
            
        }
        vector<int> v ;
        return v;
    }
};