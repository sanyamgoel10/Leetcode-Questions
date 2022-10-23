class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        int sum = n*(n+1)/2;
        
        vector<int> ans;
        vector<int> temp(n+1,0);
        for(int i=0;i<n;i++){
            temp[nums[i]]++;
            sum -= nums[i];
            if(temp[nums[i]]==2){
                ans.push_back(nums[i]);
                sum += nums[i];
            }
            
        }
        ans.push_back(sum);
        
        return ans;
    }
};