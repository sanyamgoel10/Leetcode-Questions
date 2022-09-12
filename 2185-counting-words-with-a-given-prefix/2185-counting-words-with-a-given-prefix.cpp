class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int prefSize = pref.size();
        
        int ans = 0;
        
        for(auto x : words){
            if(x.substr(0,prefSize) == pref)
                ans++;
        }
        
        return ans;
    }
};