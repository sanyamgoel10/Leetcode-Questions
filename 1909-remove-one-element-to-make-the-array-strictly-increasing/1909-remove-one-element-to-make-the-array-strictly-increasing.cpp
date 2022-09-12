class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        
        int cnt = 0;
        for(int i=1;i<n;i++){
            int prev = nums[i-1];
            int curr = nums[i];
            if(prev>=curr){
                if(i>=2 && nums[i-2]>=curr){
                    nums[i] = nums[i-1];
                }
                cnt++;
            }
        }
        
        return cnt==1 || cnt==0;
    }
};