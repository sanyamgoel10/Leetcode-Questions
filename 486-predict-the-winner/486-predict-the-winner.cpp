class Solution {
    bool solve(int l, int r, vector<int>& nums, int p1, int p2, bool flag){
        if(l>r){
            return p1>=p2;
        }
        
        //flag 1 -> player 1
        //flag 0 -> player 2
        
        if(flag==1){
            return solve(l+1,r,nums,p1+nums[l],p2,0) || solve(l,r-1,nums,p1+nums[r],p2,0);
        }
        else{
            return solve(l+1,r,nums,p1,p2+nums[l],1) && solve(l,r-1,nums,p1,p2+nums[r],1);
        }
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        int p1 = 0;
        int p2 = 0;
        
        return solve(0, n-1, nums, p1, p2, 1);
    }
};