class Solution {
public:
    int numSub(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        int ans = 0;
        
        int i = 0;
        while(i<n){
            if(s[i]=='1'){
                int j = i;
                while(s[j] == '1' && j<n){
                    j++;
                }
                long long x = j-i;    //number of consecutive 1's
                long long temp = (x*(x+1)/2) % mod;
                ans += temp;
                i=j;
            }
            i++;
        }
        
        return ans;
    }
};