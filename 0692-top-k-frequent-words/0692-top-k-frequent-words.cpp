class Solution {
    static bool cmp(pair<string,int>& a, pair<string,int>& b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    void sortMap(map<string, int>& hmap, int& k, vector<string>& ans){
        vector<pair<string,int>> temp;
        for(auto& x : hmap){
            temp.push_back(x);
        }
        sort(temp.begin(), temp.end(), cmp);
        
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].first);
        }
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> hmap;
        for(auto x : words){
            hmap[x]++;
        }
        
        vector<string> ans;
        
        sortMap(hmap, k, ans);
        
        // for(auto x :  hmap){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        return ans;
    }
};