class Solution {
    void solve(vector<int>& cells, const int& n){
        for(int k = 0;k<n;k++){
            vector<int> temp(8,0);
            for(int i=1;i<7;i++){
                if(cells[i-1]==cells[i+1]){
                    temp[i] = 1;
                }
            }
            cells = temp;
        }
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        if(n==0){
            return cells;
        }
        //the pattern repeats in every 14 days
        //hence get result for every 14 days until last
        
        solve(cells, 1);    //Prison cells for one day, The pattern repeats from day 1 - 14
        solve(cells, (n-1)%14); //Simply day 14 = day 1, Day 0 never repeats because of corners  
        
        return cells;
    }
};