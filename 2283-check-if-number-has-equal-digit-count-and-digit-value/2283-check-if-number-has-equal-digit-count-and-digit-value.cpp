class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        
        unordered_map<int,int> hmap;
        for(auto& x : num){
            hmap[x-'0']++;
        }
        
        for(int i=0;i<n;i++){
            if(hmap[i] != num[i]-'0')
                return false;
        }
        
        return true;
    }
};