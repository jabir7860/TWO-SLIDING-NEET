
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,n=s.length(); 
        unordered_map<char,int>mp; 
        int ans=0; 
        int maxF=0; 
        while(r<n){
            mp[s[r]]++; 
            maxF=max(maxF,mp[s[r]]); 
            while((r-l+1)-maxF>k){
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
SC : O(ans) 
