class Solution {
    unordered_map<int,vector<int>> hmap;
public:
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            hmap[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> temp = hmap[target];
        int n = temp.size();
        return hmap[target][rand()%n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */