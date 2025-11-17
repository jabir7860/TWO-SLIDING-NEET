class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size();
        int prod=1,ans=0; 
        while(r<n){
            prod=prod*nums[r]; 
            while(prod>=k && l<r && prod!=0){
                prod/=nums[l]; 
                l++; 
            }
            if(prod<k) ans+=(r-l+1); 
            r++; 
        }
        return ans; 
    }
};
TC : O(N) 
SC : O(1) 
