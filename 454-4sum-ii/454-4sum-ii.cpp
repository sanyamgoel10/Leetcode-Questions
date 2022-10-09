class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        
        unordered_map<int,int> hmap;
        
        //store two sum in hashmap with their frequencies
        for(auto x : nums1){
            for(auto y : nums2){
                int sum = x + y;
                hmap[sum]++;
            }
        }
        
        //find two sum of all indices in num3, num4 and find its negative in hashmap and its frequency
        //then add those frequency to the answer
        for(auto x : nums3){
            for(auto y : nums4){
                int sum = x + y;
                if(hmap[-sum]){
                    ans += hmap[-sum];
                }
            }
        }
        
        return ans;
    }
};