class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0; 
        int l=0,r=0,n=s.length(); 
        unordered_map<int,int>mp; 
        while(r<n){
            mp[s[r]]++; 
            while(mp[s[r]]>1 && l<r){
                mp[s[l]]--; 
                if(mp[s[l]]==0) mp.erase(s[l]); 
                l++; 
            }
            ans=max(ans,r-l+1); 
            r++; 
        }
        return ans; 
    }
};

TC : O(N) 
SC : O(1) -> only 26 characters of abcdefghijklmnopqrstuvwxyz 
