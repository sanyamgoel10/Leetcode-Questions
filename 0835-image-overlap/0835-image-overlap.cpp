class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        //firstly, store positions of 1's in both images in two vectors a and b
        vector<vector<int>> a;
        vector<vector<int>> b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    a.push_back({i,j});
                }
                if(img2[i][j]==1){
                    b.push_back({i,j});
                }
            }
        }
        
        int ans = 0;
        
        //now, loop through the store positions of 1's in both arrays
        //and find sliding patterns
        map<vector<int>,int> hmap;
        for(auto x : a){
            for(auto y : b){
                int ai = x[0];
                int aj = x[1];
                int bi = y[0];
                int bj = y[1];
                vector<int> temp = {bi-ai, bj-aj};
                hmap[temp]++;
                ans = max(ans, hmap[temp]);
            }
        }
        
        return ans;
    }
};