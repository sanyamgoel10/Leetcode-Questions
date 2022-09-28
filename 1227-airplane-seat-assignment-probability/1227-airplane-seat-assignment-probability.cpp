class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        //by mathematical induction, answer will always be 0.5.
        
        /*
            After the first person, neither of the passengers show any preference for the last person's seat nor the seat of the first passenger.

Once all the passengers except the last passenger occupy the seats, the first passenger would be sitting in the seat allotted to him or in that of the last person.

Therefore, the probability that the last person to board gets his assigned seat unoccupied is

        */
        
        if(n<2){
            return 1;
        }
        return (double)1/(double)2;
    }
};