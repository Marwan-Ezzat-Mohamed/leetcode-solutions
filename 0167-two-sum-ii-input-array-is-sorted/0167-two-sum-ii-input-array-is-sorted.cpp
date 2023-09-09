#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        unordered_set<int>st;
        for(auto x : numbers)st.insert(x);
        

        for (auto x = st.begin(); x != st.end(); ++x ){
            int search = target - (*x);
        

            auto it = st.find(search);

            if (it != st.end()){
                vector<int> ans;
                
                int index1= lower_bound(numbers.begin(), numbers.end(), *it)
                - numbers.begin();
                
                int index2= upper_bound(numbers.begin(), numbers.end(), *x)
                - numbers.begin();
                ans.push_back(index1 +1);
                ans.push_back(index2 );
                sort(ans.begin(),ans.end());
                return ans;
            }
   
        }
              vector<int> ans;
        return ans;
        
    }
};