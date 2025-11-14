class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size(); 
        int k=0; 
        for(auto i:nums) k+=i; 
        k=k-x; 
        if(k==0) return n; 
        int l=0,r=0; 
        int sum=0;
        int ans=0;  
        while(r<n){
            sum+=nums[r]; 
            while(sum>k && l<r){
                sum=sum-nums[l]; 
                l++; 
            }
            if(sum==k){
                ans=max(ans,r-l+1); 
            }
            r++; 
        }
        if(ans) return n-ans; 
        return -1; 
    }
};
TC : O(N) 
  SC : O(1) 
