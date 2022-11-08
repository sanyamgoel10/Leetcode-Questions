class Solution {
    int solve(int house, vector<int>& heaters){
        //calculating the distance of nearest heater to the given house
        
        int l = 0;
        int r = heaters.size()-1;
        
        while(l<=r){
            int mid = (l+r)/2;
            if(heaters[mid] == house){
                return 0;
            }
            if(heaters[mid] < house){
                l = mid+1;
            }
            if(heaters[mid] > house){
                r = mid-1;
            }
        }
        
        return min(heaters[l]-house, house-heaters[r]);
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int ans = 0;
        
        for(auto x : houses){
            if(x <= heaters[0]){
                //edge case for first heater and first house
                ans = max(ans, heaters[0]-x);
            }
            else if(x >= heaters[heaters.size()-1]){
                //edge case for last heater and last house
                ans = max(ans, x-heaters[heaters.size()-1]);
            }
            else{
                ans = max(ans, solve(x,heaters));
            }
        }
        
        return ans;
    }
};