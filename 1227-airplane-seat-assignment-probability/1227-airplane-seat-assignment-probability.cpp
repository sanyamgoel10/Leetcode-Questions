class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        //by mathematical induction, answer will always be 0.5
        if(n>=2){
            return (double)1/(double)2;
        }
        return 1;
    }
};