class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size(); 
        n=colors.size();
        int ans=0;  
        for(int i=0;i<n;i++){
            if(colors[(n-1+i)%n]!=colors[i] && colors[i]!=colors[(n+1+i)%n]){
                ans++; 
            }
        }
        return ans; 
    }
};

TC : O(N) 
SC : O(1)
