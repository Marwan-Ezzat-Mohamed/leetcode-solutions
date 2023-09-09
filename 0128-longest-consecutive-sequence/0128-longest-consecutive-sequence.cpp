class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int ans=0;
        for (auto x: nums)st.insert(x);
        
        for ( auto x:st ){
            int val = x;
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