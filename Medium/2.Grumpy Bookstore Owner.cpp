class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0; 
        int n=grumpy.size();
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                ans=ans+customers[i]; 
            }
        }
        cout<<"ANS:"<<ans<<endl; 
        int l=0,r=0; 
        int sum=0; 
        int jabir=0; 
        while(r<n){
            if(grumpy[r]==1){
                sum=sum+customers[r]; 
            }
            if(r-l+1>minutes){
                if(grumpy[l]==1){
                    sum=sum-customers[l]; 
                }
                    l++; 
            }
            if(r-l+1==minutes) cout<<"SUM:"<<sum<<endl; 
            jabir=max(jabir,sum); 
            r++; 
        }
        return jabir+ans; 
    }
};

TC : O(N) 
SC : O(1) 
