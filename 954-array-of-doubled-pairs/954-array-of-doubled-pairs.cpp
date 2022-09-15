class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        if(n%2!=0){
            return false;
        }
        unordered_map<int,int> hmap;
        for(auto x : arr){
            hmap[x]++;
        }
        
        sort(arr.begin(), arr.end());
        
        for(auto x : arr){
            if(hmap[x] && hmap[2*x]){
                hmap[x]--;
                hmap[2*x]--;
            }
        }
        
        for(auto x : hmap){
            if(x.second != 0){
                return false;
            }
        }
        
        return true;
    }
};