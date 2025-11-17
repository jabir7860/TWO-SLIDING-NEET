class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size(); 
        unordered_map<int,int>mp; 
        int ans=0; 
        while(r<n){
            mp[nums[r]]++; 
            while(mp[nums[r]]>k){
                mp[nums[l]]--; 
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]); 
                }
                l++; 
            }
            ans=max(ans,r-l+1); 
            r++; 
        }
        return ans; 
    }
};

TC : O(N )
SC : O(1) 
