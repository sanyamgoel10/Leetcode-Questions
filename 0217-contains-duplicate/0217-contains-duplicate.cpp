class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> hmap;
        for(auto x : nums){
            if(hmap.count(x)){
                return true;
            }
            hmap[x]++;
        }
        return false;
    }
};