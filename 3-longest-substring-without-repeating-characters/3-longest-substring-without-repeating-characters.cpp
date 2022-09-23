class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            unordered_map<char,int> hmap;
            int j = i;
            while(hmap.count(s[j])==false && j<n){
                hmap[s[j]]++;
                j++;
            }
            ans = max(ans, j-i);
        }
        
        return ans;
    }
};