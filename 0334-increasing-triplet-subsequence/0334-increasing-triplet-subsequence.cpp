class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        //take two numbers left and mid
        int left = INT_MAX;
        int mid = INT_MAX;
        
        for(auto x : nums){
            //x is the right number
            if(x > mid){
                //because left<mid<x
                return true;
            }
            else if(left<x && x<mid){
                //update mid because x lies in between left and mid
                mid = x;
            }
            else if(x < left){
                //update left because x lies before left
                left = x;
            }
        }
        
        return false;
    }
};