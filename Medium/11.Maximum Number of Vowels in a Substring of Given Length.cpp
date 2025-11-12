class Solution {
public:
bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
    int maxVowels(string s, int k) {
        int l=0,r=0,n=s.length(); 
        int ans=0;
        int count=0;
        while(r<n){
            if(isVowel(s[r])) count++; 
            if((r-l+1)>k){
                if(isVowel(s[l])){
                    count--; 
                }
                l++; 
            }
            if(r-l+1==k) ans=max(ans,count); 
            r++; 
        }
        return ans; 
    }
};

TC : O(N) 
  SC : O1) 
