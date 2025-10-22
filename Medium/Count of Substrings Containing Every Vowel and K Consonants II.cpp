class Solution {
public:
    bool isvowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return 1; 
        return 0; 
    }
    long long fun(string word,int k){
        long long l=0,r=0,n=word.length(); 
        unordered_map<char,int>mp; 
        long long c_c=0; 
        long long count=0; 
        while(r<n){
            if(isvowel(word[r])){
                mp[word[r]]++; 
            }
            else{
                c_c++; 
            }
            while(mp.size()>=5 && c_c>k){
                if(isvowel(word[l])){
                    mp[word[l]]--; 
                    if(mp[word[l]]==0) mp.erase(word[l]); 
                    l++; 
                }
                else{
                    c_c-=1; 
                    l++; 
                }
            }
            count+=(r-l+1); 
            r++; 
        }
        return count; 
    }
    long long countOfSubstrings(string word, int k) {
        long long a=fun(word,k); 
        long long  b=fun(word,k-1); 
        return abs(a-b); 
    }
};
TC : O(N) 
SC : O(1) 
