class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0; 
        int l=0,r=0,n=nums.size(); 
        long long sum=0; 
        set<int>st; 
        while(r<n){
            while(st.find(nums[r])!=st.end()){
                sum=sum-nums[l]; 
                st.erase(nums[l]); 
                l++; 
            }
            sum+=nums[r]; 
            while(r-l+1>k || st.find(nums[r])!=st.end()){
                sum=sum-nums[l]; 
                st.erase(nums[l]); 
                l++; 
            }
            if(r-l+1==k){
                ans=max(ans,(long long)sum); 
            }
            st.insert(nums[r]); 
            r++; 
        }
        return ans; 
    }
};
TC : O(N) 
  SC : (1) 
