class Solution {
public:
    int fun(int i,int j,string s,int k,int a,int b,int c,int time){
        if(a>=k && b>=k && c>=k) return time; 
        if(i>j) return 1e9; 
        int left=1e9; 
        if(s[i]=='a') left=fun(i+1,j,s,k,a+1,b,c,time+1); 
        else if(s[i]=='b') left=fun(i+1,j,s,k,a,b+1,c,time+1);
        else left=fun(i+1,j,s,k,a,b,c+1,time+1); 

        int right=1e9; 
        if(s[j]=='a') right=fun(i,j-1,s,k,a+1,b,c,time+1); 
        else if(s[j]=='b') right=fun(i,j-1,s,k,a,b+1,c,time+1); 
        else right=fun(i,j-1,s,k,a,b,c+1,time+1); 

        return min(left,right); 
    }
    int takeCharacters(string s, int k) {
        int ans=fun(0,s.length()-1,s,k,0,0,0,0); 
        if(ans==1e9) return -1; 
        return ans; 
    }
};
TC : O(2^N) 
SC : O(N) 
============================================================================================================================
class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        int n=s.size();
        unordered_map<char, int> mp;
        for(auto it:s)  mp[it]++;
        if(mp['a']<k || mp['b']<k || mp['c']<k) return -1;
        int mini=n;
        int i=n-1, j=n-1;

        while(i>=0)
        {
            mp[s[i]]--;
            while(mp['a']<k || mp['b']<k || mp['c']<k)
            {
                mp[s[j]]++;
                j--;
            }
            mini = min(mini, i+n-1-j);
            i--;
        }
        return mini;
    }
};

TC : O(N) 
SC : O(N) 
