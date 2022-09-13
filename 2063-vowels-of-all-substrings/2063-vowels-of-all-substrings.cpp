class Solution {
public:
    long long countVowels(string word) {
        //DP tabulation solution
        
        int n = word.size();
        unordered_map<char,int> hmap;
        hmap['a']=1;
        hmap['e']=1;
        hmap['i']=1;
        hmap['o']=1;
        hmap['u']=1;
        
        long long ans = 0;
        
        vector<long long> dp(n, 0);
        
        if(hmap.count(word[0])){
            dp[0] = 1;
        }
        
        for(int i=1;i<n;i++){
            dp[i] = dp[i-1];
            if(hmap.count(word[i])){
                dp[i] += i+1;
            }
        }
        
        for(auto x : dp){
            ans += x;
        }
        
        return ans;
    }
};