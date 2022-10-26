class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> hmap;    //store prefix sums in a hmap with each index
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum%k==0 && i>0){
                //current sum divisible by k, return true
                return true;
            }
            if(hmap.count(sum%k) && i-hmap[sum%k]>=2){
                //current sum's remainder present in hmap and its continous subarray size is >=2
                return true;
            }
            if(hmap.count(sum%k)==0){
                //add current sum's remainder in the hmap
                hmap[sum%k] = i;
            }
        }
        return false;
    }
};