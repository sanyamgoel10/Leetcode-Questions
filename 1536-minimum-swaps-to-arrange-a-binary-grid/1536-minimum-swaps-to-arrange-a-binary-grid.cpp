class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        // which elements should be 0 in each row
        // 1st row -> 2-n
        // 2nd row -> 3-n
        // .
        // .
        // mth row -> n-1
        int n = grid.size();
        
        vector<int> hmap(n);
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1){
                    break;
                }
                cnt++;
            }
            hmap[i] = cnt;
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            int k = i;
            int req = n-1-i;    //required number of zeroes from end
            
            while(k<n && hmap[k]<req){
                //find the first row which is best suitable for current box
                k++;
            }
            if(k==n){
                return -1;  //required tailing zeroes not found
            }
            
            ans += k-i;
            
            while(k>0){
                hmap[k] = hmap[k-1];    //removing the current row from hmap because its taken
                k--;
            }
        }
        
        return ans;
    }
};