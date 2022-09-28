class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        //firstly, store count of SDP's at each index
        //store them in a dp array
        //then find sum of all dp array values, i.e., sum of all the SDP's at all indexes
        
        int n = prices.size();
        if(n==1){
            return 1;
        }
        
        vector<int> dp(n);
        dp[0] = 1;
        
        for(int i=1;i<n;i++){
            if(prices[i-1]-prices[i] == 1){
                dp[i] = 1 + dp[i-1];
            }
            else{
                dp[i] = 1;
            }
        }
        
        long long ans = 0;
        for(auto x : dp){
            ans += x;
        }
        
        return ans;
    }
};