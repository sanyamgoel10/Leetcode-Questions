class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> hmap;
        
        for(auto x : nums){
            hmap[x]++;
        }
        
        int ans = 0;
        
        for(auto x : hmap){
            if(hmap.count(x.first-1)){
                int temp = x.second + hmap[x.first-1];
                ans = max(ans, temp);
            }
        }
        
        return ans;
    }
};