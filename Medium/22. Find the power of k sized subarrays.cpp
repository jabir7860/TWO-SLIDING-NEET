class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size(); 
        vector<int>ans; 
        while(r<n){
            while(r-l+1>k){
                l++; 
            }
            if(r-l+1==k)
            {
              vector<int> newArr(nums.begin() + (l), nums.begin() + r+1); 
              // sort(newArr.begin(),newArr.end()); 
              // cout<<l<<" "<<r<<endl; 
              // for(auto i:newArr) cout<<i<<" "; 
              // cout<<endl; 
              bool f=0; 
              for(int i=1;i<newArr.size();i++){
                if(newArr[i-1]!=newArr[i]-1)
                {
                    f=1; 
                }
              }
              if(f==0){
                ans.push_back(newArr[newArr.size()-1]); 
              }
              else ans.push_back(-1); 
            }
            r++; 
        }
        return ans; 
    }
};
TC : O(N*K) where k is size of internal subarray that is formed; 
SC : O(N) 


    class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int l=0,r=1,n=nums.size(); 
        if(k==1) return nums; 
        vector<int>ans; 
        int count=1; 
        while(r<n){
            if(nums[r]-1==nums[r-1]){
                count++; 
            }
            else{
                count=1; 
            } 
            if(r>=k-1){
                if(count>=k){
                    ans.push_back(nums[r]); 
                }
                else{
                    ans.push_back(-1); 
                }
            }
            r++;
        }
        return ans;   
    }
};

tc :o(n) 
sc : o(k)
