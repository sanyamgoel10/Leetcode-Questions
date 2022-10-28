class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        
        map<vector<int>,vector<string>> hmap;
        for(auto x : strs){
            vector<int> alpha(26);
            for(auto y : x){
                alpha[y-'a']++;
            }
            if(hmap.count(alpha)){
                hmap[alpha].push_back(x);
            }
            else{
                hmap[alpha] = {x};
            }
        }
        for(auto x : hmap){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};