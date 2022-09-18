class Solution {
    int solve(int i, int n, unordered_map<int,vector<int>>& hmap, vector<vector<int>>& dp){
        if(n==1){
            //base case -> when we reach n-digits number
            return 1;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        
        int ans = 0;
        for(auto x : hmap[i]){
            //iterating over all next positions of current digit
            ans += solve(x, n-1, hmap, dp);
            ans %= (int)1e9 + 7;
        }
        
        return dp[n][i] = ans;
    }
public:
    int knightDialer(int n) {
        unordered_map<int,vector<int>> hmap = {{0,{4,6}},
                                               {1,{6,8}},
                                               {2,{7,9}},
                                               {3,{4,8}},
                                               {4,{0,3,9}},
                                               {5,{}},
                                               {6,{0,1,7}},
                                               {7,{2,6}},
                                               {8,{1,3}},
                                               {9,{4,2}}};
        
        vector<vector<int>> dp(n+1, vector<int>(10,-1));
        
        int ans = 0;
        for(int i=0;i<10;i++){
            //choosing every number from 0 to 9 as starting point
            //and add its answer to the result
            ans += solve(i, n, hmap, dp);
            ans %= (int)1e9 + 7;
        }
        
        return ans;
    }
};