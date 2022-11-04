class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto& x : nums){
            if(to_string(x).size()%2==0)
                ans++;
        }
        
        return ans;
    }
};