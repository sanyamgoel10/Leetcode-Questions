class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n,0);
        
        int sum = 0;
        for(auto x : nums){
            if(x%2==0)
                sum += x;
        }
        
        for(int i=0;i<n;i++){
            int val = queries[i][0];
            int ind = queries[i][1];
            
            int previ = nums[ind];
            nums[ind] += val;
            
            // int currSum = sum;
            if(previ%2==0){
                sum -= previ;
                if(nums[ind]%2==0){
                    sum += nums[ind];
                }
            }
            else{
                if(nums[ind]%2==0){
                    sum += nums[ind];
                }
            }
            
            ans[i] = sum;
        }
        
        return ans;
    }
};