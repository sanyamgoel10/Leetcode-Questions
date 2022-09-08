class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n==0 || n==1){
            return 0;
        }
        
        int l = 0;
        int r = n-1;
        
        int maxi = 0;
        
        while(l<r){
            int currVol = min(height[l], height[r]) * (r-l);
            maxi = max(currVol, maxi);
            
            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        
        return maxi;
    }
};