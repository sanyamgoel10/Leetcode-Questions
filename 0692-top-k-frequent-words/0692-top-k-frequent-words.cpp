class Solution {
    static bool cmp(pair<string,int>& a, pair<string,int>& b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hmap;
        for(auto x : words){
            hmap[x]++;
        }
        vector<pair<string,int>> temp;
        for(auto x : hmap){
            temp.push_back(x);
        }
        
        sort(temp.begin(), temp.end(), cmp);
        
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].first);
        }
        
        return ans;
    }
};