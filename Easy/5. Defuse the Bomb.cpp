class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // 5  7  1   4 
        vector<int>temp=code; 
        int n=code.size(); 
        if(k==0){
            for(int i=0;i<n;i++){
                code[i]=0; 
            }
            return code; 
        }
        if(k>0){
            for(int i=0;i<n;i++){
                int sum=0; 
                cout<<"I:"<<i<<endl; 
                for(int j=(i+1);j<(i+k+1);j++){
                    sum+=temp[j%n]; 
                    cout<<"J:"<<j<<"SUM:"<<sum<<" "<<j%n<<endl; 
                }
                code[i]=sum; 
            }
            return code; 
        }
        if(k<0){
            for(int i=n-1;i>=0;i--){
                int sum=0; 
                cout<<"I:"<<i<<endl; 
                for(int j=i-1;j>=i+k;j--){
                    sum+=temp[(j+n)%n]; 
                    cout<<"J:"<<j<<"SUM:"<<sum<<" "<<j%n<<endl; 
                }   
                code[i]=sum; 
            }
            return code; 
        }
        return {}; 
    }
};

TC : O(N) 
SC : O(N) 
