class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // TC -> O(nlongn) + O(n)*O(n) == O(nlogn)+O(n^2)
        
        int n = nums.size();
        //sort the array to use 2pointer technique
        sort(nums.begin(), nums.end());
        
        //take initial sum as sum of 1st 3 values
        int sum = nums[0] + nums[1] + nums[2];
        
        // i -> pointer from start to 3rd last index
        // l,r -> left and right pointers to move inside the range of (i,n-1)
        for(int i=0;i<n-2;i++){
            int l = i+1;
            int r = n-1;
            
            while(l<r){
                //find the current sum st every pointers
                int currSum = nums[i] + nums[l] + nums[r];
                //if current sum is more close to global sum, update the global sum
                if(abs(currSum-target) < abs(sum-target)){
                    sum = currSum;
                }
                //since array is sorted, move the l and r pointers according to if sum is greater than or less than target, always try to balance the current sum, hence choose l++ or r-- accordingly
                if(currSum > target){
                    r--;
                }
                else if(currSum < target){
                    l++;
                }
                else{
                    return target;
                }
            }
        }
        
        return sum;
    }
};