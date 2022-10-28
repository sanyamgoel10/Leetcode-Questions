class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        for(auto x : nums){
            prod *= x;
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                int temp = 1;
                for(int j=0;j<nums.size();j++){
                    if(j==i)
                        continue;
                    temp*=nums[j];
                }
                ans[i] = temp;
            }
            else{
                ans[i] = prod/nums[i];
            }
        }
        return ans;
    }
};