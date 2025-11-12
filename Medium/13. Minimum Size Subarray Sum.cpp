class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums){
        /* 

        */ 
        int l=0,r=0,n=nums.size(),sum=0; 
        int ans=1e9; 
        while(r<n){
            sum=sum+nums[r];
            cout<<"OutSide:"<<sum<<endl; 
            while(sum>=target){
                ans=min(ans,r-l+1); 
                sum=sum-nums[l];
                cout<<"Inside:"<<sum<<endl; 
                l++; 
            }
            r++; 
        }
        if(ans==1e9) return 0; 
        return ans; 
    }
};

TC : O(N) 
|SC : O(1) 
