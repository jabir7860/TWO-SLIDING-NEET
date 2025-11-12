class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // sort(fruits.begin(),fruits.end()); 
        int l=0,r=0,n=fruits.size(); 
        int ans=0; 
        unordered_map<int,int>mp; 
        while(r<n){
            mp[fruits[r]]++; 
            if(mp.size()>2 && l<r){
                mp[fruits[l]]--; 
                if(mp[fruits[l]]==0) mp.erase(fruits[l]); 
                l++; 
            }
            if(mp.size()<=2)
                ans=max(ans,r-l+1); 
            r++; 
        }
        return ans; 
    }
};

TC : O(N) 
  SC :O(1)
