class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int l = 0;
        int r = 0;
        int ans = INT_MAX;
        int sum = 0;
        
        while(r<n){
            sum += nums[r++];
            while(sum >= target){
                ans = min(ans, r-l);
                sum -= nums[l++];
            }
        }
        
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};