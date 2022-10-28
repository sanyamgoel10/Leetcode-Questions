class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n != r*c){
            return mat;
        }
        
        vector<int> temp;
        for(auto x : mat){
            for(auto y : x){
                temp.push_back(y);
            }
        }
        
        vector<vector<int>> ans(r, vector<int>(c));
        int ind = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j] = temp[ind];
                ind++;
            }
        }
        
        return ans;
    }
};