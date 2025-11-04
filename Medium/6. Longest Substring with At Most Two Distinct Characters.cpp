int lengthOfLongestSubstring(string s) {
    int l=0,r=0,n=s.length(); 
    unordered_map<char,int>mp;
    int ans=0;
    while(r<n){
        mp[s[r]]++; 
        while(mp.size()>2){
            mp[s[l]]--; 
            if(mp[s[l]]==0){
                mp.erase(s[l]); 
            }
            l++; 
        }
        ans=max(r-l+1,ans); 
        r++; 
    }
    return ans; 
}
TC : O(N)
SC : O(1) 
