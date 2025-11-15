class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length(); 
        int l=0,r=0; 
        int cost=0; 
        int ans=0; 
        while(r<n){
            cost=cost+abs(s[r]-t[r]); 
            while(cost>maxCost){
                cost=cost-abs(s[l]-t[l]); 
                l++; 
            }
            ans=max(ans,r-l+1); 
            r++; 
        }
        return ans; 
    }
};
TC : O(N) 
SC : O(1) 
