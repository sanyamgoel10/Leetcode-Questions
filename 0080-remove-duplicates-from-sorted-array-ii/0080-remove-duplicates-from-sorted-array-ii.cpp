class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if(n==0 || n==1 || n==2){
            return n;
        }
        
        int l = 2;
        int r = 2;
        
        while(r<n){
            //always check for current element and element at 2 steps before current
            //if they are not equal, change left element by right and go on
            if(nums[r] != nums[l-2]){
                nums[l] = nums[r];
                l++;
            }
            r++;
        }
        
        return l;
    }
};