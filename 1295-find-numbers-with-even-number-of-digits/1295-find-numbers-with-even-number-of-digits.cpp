class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto x : nums){
            int cnt = to_string(x).size();
            if(cnt%2==0)
                ans++;
        }
        
        return ans;
    }
};