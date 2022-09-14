class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hmap = {{'I', 1},
                                           {'V', 5},
                                           {'X', 10},
                                           {'L', 50},
                                           {'C', 100},
                                           {'D', 500},
                                           {'M', 1000}
                                          };
        
        int n = s.size();
        
        int ans = hmap[s[n-1]];
        
        for(int i=n-2;i>=0;i--){
            if(hmap[s[i]] < hmap[s[i+1]]){
                ans -= hmap[s[i]];
            }
            else{
                ans += hmap[s[i]];
            }
        }
        
        return ans;
    }
};