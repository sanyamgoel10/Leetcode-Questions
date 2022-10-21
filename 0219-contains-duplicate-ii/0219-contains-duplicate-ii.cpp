class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> hmap;
        for(int i=0;i<n;i++){
            if(hmap.count(nums[i])){
                if(abs(hmap[nums[i]]-i)<=k){
                    return true;
                }
            }
            hmap[nums[i]] = i;
        }
        
        return false;
    }
};