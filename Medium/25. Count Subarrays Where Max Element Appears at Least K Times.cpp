class Solution {
public:
    long long fun(vector<int>&nums,int k,int mx){
        long long ans=0; 
        int l=0,r=0,n=nums.size(); 
        unordered_map<int,int>mp; 
        while(r<n){
            mp[nums[r]]++; 
            while(mp[mx]>k){
                mp[nums[l]]--; 
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]); 
                }
                l++; 
            }
            if(mp[mx]<=k) ans=ans+(long long)(r-l+1); 
            r++; 
        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=0; 
        long long n=nums.size(); 
        for(int i=0;i<n;i++) mx=max(mx,nums[i]); 
        long long a=fun(nums,k-1,mx);  
        cout<<a<<endl; 
        return (long long)(n*(n+1))/2-(long long)a;  
    }
};
TC : O(N) 
SC : O(1)
