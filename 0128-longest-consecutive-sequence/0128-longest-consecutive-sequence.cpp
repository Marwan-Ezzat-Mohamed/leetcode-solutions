class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (auto x: nums)st.insert(x);
        
        int ans=0;
        
        for ( auto it = st.begin(); it != st.end(); ++it ){
            int val = *it;
            if (st.find(val-1)==st.end()){
                //then we have the smallest element in the sequence
                int len=1;
                int cur=val;
                while(st.find(cur+1)!=st.end()){
                    len++;
                    cur++;
                }
                ans=max(ans,len);
                
            }
        }   
        return  ans;
    }
};