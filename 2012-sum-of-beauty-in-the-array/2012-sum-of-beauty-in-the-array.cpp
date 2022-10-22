class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        vector<int> maxTillNow(n);  //prefix maximum array
        vector<int> minTillEnd(n);  //suffix minimum array
        
        maxTillNow[0] = nums[0];     //maximum in prefix array
        minTillEnd[n-1] = nums[n-1];     //minimum in suffix array
        for(int i=1;i<n-1;i++){ 
            // maxTillNow[i] = maxi;
            maxTillNow[i] = max(maxTillNow[i-1], nums[i]);
        }
        for(int i=n-2;i>0;i--){
            // minTillEnd[i] = mini;
            minTillEnd[i] = min(minTillEnd[i+1], nums[i]);
        }
        
        for(int i=1;i<n-1;i++){
            if(maxTillNow[i-1]<nums[i] && nums[i]<minTillEnd[i+1]){
                ans += 2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                ans++;
            }
        }
        
        return ans;
    }
};