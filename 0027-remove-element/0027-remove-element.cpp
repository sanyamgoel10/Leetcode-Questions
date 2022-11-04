class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        
        int k = 0;
        int prev = 0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                swap(nums[i], nums[prev]);
                prev++;
            }
            else{
                k++;
            }
        }
        
        return n-k;
    }
};