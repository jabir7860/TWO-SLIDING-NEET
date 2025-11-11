class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, n = nums.size();
        long long sum = 0;   // <-- use long long
        long long ans = 0;   // <-- also make ans long long (optional, for safety)
        while (r < n) {
            sum += nums[r];
            long long curr = nums[r];
            while ((long long)(r - l + 1) * curr - sum > k) {
                sum -= nums[l];
                l++;
            }
            ans = max(ans, (long long)(r - l + 1));
            r++;
        }
        return (int)ans;
    }
};

TC : O(N*LOG N) 
SC : O(1) 
