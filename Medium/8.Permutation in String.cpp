class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(); 
        int n2=s2.length(); 
        int l=0,r=0; 
        unordered_map<char,int>mp1; 
        unordered_map<char,int>mp2; 
        for(auto i:s1) mp1[i]++; 
        while(r<n2){
            mp2[s2[r]]++; 
            if(r-l+1>n1){
                mp2[s2[l]]--; 
                if(mp2[s2[l]]==0) mp2.erase(s2[l]); 
                l++; 
            }
            if(mp1==mp2) return 1; 
            r++; 
        }
        return 0; 
    }
};

TC : O(N) 
SC : O(1) 
