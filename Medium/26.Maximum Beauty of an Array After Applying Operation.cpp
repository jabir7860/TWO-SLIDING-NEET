// Try Your Own 

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1;

        int l = 0;
        for (int r = 0; r < n; r++) {
            // shrink window until it becomes valid
            while (nums[r] - nums[l] > 2 * k) {
                l++;
            }
            // window [l, r] is valid
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


TC : O(N) 
SC : O91_ 
