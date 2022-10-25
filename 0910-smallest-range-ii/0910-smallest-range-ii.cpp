class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int ans = nums[n-1]-nums[0];
        
        int left = nums[0]; //global minimum value
        int right = nums[n-1];  //global maximum value
        
        for(int i=0;i<n-1;i++){
            //max value at every point is maximum of (global max value - k) and (current max value)
            int maxi = max(right-k, nums[i]+k);
            
            //min value at every point is min of (global min value + k) and (current min value)
            int mini = min(left+k, nums[i+1]-k);
            
            ans = min(ans, maxi-mini);
        }
        return ans;
    }
};