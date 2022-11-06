class Solution {
    int n;
    vector<int> arr;
public:
    Solution(vector<int>& nums) {
        this->n = nums.size();
        this->arr = nums;
    }
    
    int pick(int target) {
        int ans;
        while(true){
            //find any index in the array using rand()
            int ind = rand()%n;
            //if that index value  is equal to target, return
            //else go onn
            if(arr[ind]==target){
                ans = ind;
                break;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */