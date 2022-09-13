class Solution {
    int solve(int target, int maxDoubles){
        if(target==1){
            return 0;
        }
        if(maxDoubles==0){
            return target-1;
        }
        
        if(target>1 && target%2!=0)
            return 1 + solve(target-1, maxDoubles);
        else
            return 1 + solve(target/2, maxDoubles-1);
    }
public:
    int minMoves(int target, int maxDoubles) {
        
        return solve(target, maxDoubles);
        
    }
};