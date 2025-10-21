class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int mn = nums[i];
            int mx = nums[i];
            for (int j = i; j < n; j++) {
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
                if (mx - mn <= limit)
                    ans = max(ans, j - i + 1);
                else break; 
            }
        }

        return ans;
    }
};
TC : O(N^2) 
SC : O(1) 
  ====================================================================================================================================================================
  class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size(); 
        multiset<int>st; 
        int r=0,l=0,ans=0; 
        while(r<n){
            st.insert(nums[r]); 
            int diff=*st.rbegin()-*st.begin(); 
            while(l<r && diff>limit){
                auto it=st.find(nums[l]); 
                st.erase(it); 
                diff=*st.rbegin()-*st.begin(); 
                l++; 
            }
            ans=max(ans,r-l+1); 
            r++; 
        }
        return ans; 
    }
};

TC : O(N*LOG N)
SC : O(N)
