class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        vector<int> maxTillNow(n);
        vector<int> minTillEnd(n);
        
        int maxi = INT_MIN;     //maximum in prefix array
        int mini = INT_MAX;     //minimum in suffix array
        for(int i=0;i<n;i++){ 
            maxTillNow[i] = maxi;
            maxi = max(maxi, nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            minTillEnd[i] = mini;
            mini = min(mini, nums[i]);
        }
        
        for(int i=1;i<n-1;i++){
            if(maxTillNow[i]<nums[i] && nums[i]<minTillEnd[i]){
                ans += 2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                ans += 1;
            }
        }
        
        return ans;
    }
};