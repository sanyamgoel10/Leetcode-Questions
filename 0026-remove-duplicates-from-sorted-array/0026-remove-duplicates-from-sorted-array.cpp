class Solution {
public:  
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        //  ONE APPROACH IS ALSO TO CREATE A TEMP VECTOR AND ADD UNIQUE VALUES FROM NUMS TO IT AND RETURN ITS SIZE
        
//         BRUTE FORCE APPROACH
//         int j=1;
//         for(int i=1;i<n;i++){
//             if(nums[i]!=nums[i-1]){
//                 count++;
//                 nums[j]=nums[i];
//                 j++;
//             }
//         }
        
//         return j;
        
        //  TWO POINTER APPROACH
        if(n==0 || n==1){
            return n;
        }
        int l=0;
        int r=1;
        while(l<r && r<n){
            if(nums[l]==nums[r]){
                r++;
            }
            else{
                l++;
                nums[l]=nums[r];
                r++;
            }
        }
        return l+1;
    }
};