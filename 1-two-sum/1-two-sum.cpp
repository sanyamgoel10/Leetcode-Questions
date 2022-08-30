class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hmap;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int temp = target-nums[i];
            if(hmap.find(temp)==hmap.end()){
                hmap[nums[i]] = i;
            }
            else{
                ans = {i,hmap[temp]};
            }
        }
        return ans;
    }
};