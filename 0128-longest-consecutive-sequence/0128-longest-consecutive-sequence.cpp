class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int ans=0;
        for (auto x: nums)st.insert(x);
        
        for ( auto x:st ){
            if (st.find(x-1)==st.end()){
                //then we have the smallest element in the sequence
                int len=1;
                int cur=x;
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