class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // dry run for k=3, nums = [1,2,3,4,5,6,7]
        // 1 2 3 4 5 6 7
        // 7 6 5 4 3 2 1
        // 5 6 7 4 3 2 1
        // 5 6 7 1 2 3 4
        
        int n = nums.size();
        k = k % n;  //for very large k
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};