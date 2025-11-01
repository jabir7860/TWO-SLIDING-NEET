class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        // Brute Force 
        // Generate All subarrays. 
        int count=0; 
        for(int i=0;i<arr.size();i++){
            int sum=0; 
            for(int j=i;j<arr.size();j++){
                sum=sum+arr[j]; 
                if(j-i+1==k){
                    if(sum/k>=t){
                        count++; 
                    }
                }
                else if(j-i+1>k) break; 
            }
        }
        return count; 
    }
};
TC : O(N*K) -> Second Loop runs only till size K.  
SC : O(1) -> Constant Space.

  class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int n=arr.size(); 
        int l=0,r=0; 
        int sum=0; 
        int count=0; 
        while(r<n){
            cout<<"R:"<<r<<"L:"<<l<<"SUM:"<<sum<<endl; 
            sum=sum+arr[r]; 
            while(r-l+1>k){
                sum=sum-arr[l]; 
                l++; 
            }
            if(r-l+1==k){
                if(sum/k>=t){
                    count++; 
                }
            }
            r++; 
        }
        return count; 
    }
};

TC : O(N) 
SC : O(1) 

  class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int n=arr.size(); 
        int l=0,r=0; 
        int sum=0; 
        int count=0; 
        while(r<n){
            // cout<<"R:"<<r<<"L:"<<l<<"SUM:"<<sum<<endl; 
            sum=sum+arr[r]; 
            if(r-l+1>k){
                sum=sum-arr[l]; 
                l++; 
            }
            if(r-l+1==k){
                if(sum/k>=t){
                    count++; 
                }
            }
            r++; 
        }
        return count; 
    }
};

TC : O(N) 
SC : O(1) 
