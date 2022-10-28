class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        
        unordered_map<string,vector<string>> hmap;
        for(auto x : strs){
            string alpha = x;
            sort(alpha.begin(),alpha.end());
            
            hmap[alpha].push_back(x);
        }
        for(auto x : hmap){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};