class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        int l = 0;
        int r = 0;
        int ans = 0;
        
        unordered_map<char,int> hmap;
        
        while(r<n){
            hmap[s[r]]++;
            while(hmap[s[r]] > 1){
                hmap[s[l]]--;
                l++;
            }
            
            ans = max(ans, r-l+1);
            r++;
        }
        
        return ans;
    }
};