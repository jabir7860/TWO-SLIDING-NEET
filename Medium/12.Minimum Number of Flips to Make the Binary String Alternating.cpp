class Solution {
public:
    int minFlips(string s) {
        int n=s.length(); 
        string a=""; 
        string b=""; 
        for(int i=0;i<n;i++){
            if(i%2==0) a+="1"; 
            else a+="0"; 
        }
        for(int i=0;i<n;i++){
            if(i%2==0) b+="0";
            else b+="1"; 
        }
        cout<<a<<endl; 
        cout<<b<<endl; 
        int c_a=0; 
        int c_b=0; 
        for(int i=0;i<n;i++){
            if(s[i]!=a[i]) c_a++; 
            if(s[i]!=b[i]) c_b++; 
        }
        for(int i=0;i<n;i++){
            char first = s[0]; 
            s.erase(0, 1);      
            s.push_back(first); 
            int C_A=0; 
            int C_B=0; 
            for(int i=0;i<n;i++){
                if(s[i]!=a[i]) C_A++; 
                if(s[i]!=b[i]) C_B++; 
            }
            c_a=min(c_a,C_A); 
            c_b=min(c_b,C_B); 
        }
        return min(c_a,c_b); 
    }
};
TLE  :
TC : O(N^2) 
  SC  : O(1) 
  ======================================================================================================================
  class Solution {
public:
    int minFlips(string s) {
        int m=s.length(); 
        s=s+s; 
        int n=s.length(); 
        string a=""; 
        string b=""; 
        for(int i=0;i<n;i++){
            if(i%2==0){
                a+="1"; 
                b+="0";
            } 
            else{
                a+="0"; 
                b+="1"; 
            }
        }
        int c_a=0; 
        int c_b=0; 
        int l=0,r=0;
        int C_A=1e9; 
        int C_B=1e9; 
        while(r<n){
            if(s[r]!=a[r]) c_a++; 
            if(s[r]!=b[r]) c_b++; 
            if((r-l+1)>m){
                if(s[l]!=a[l]) c_a--; 
                if(s[l]!=b[l]) c_b--; 
                l++; 
            }
            if(r-l+1==m){
                C_A=min(C_A,c_a); 
                C_B=min(C_B,c_b); 
            }
            r++; 
        }
       return min(C_A,C_B); 
    }
};

TC : O(N) 
  SC : O(1) 
