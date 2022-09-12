class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //if, power>=tokens[i] -> power=power-tokens[i], score++
        //if, score>=1 -> power=power+tokens[i], score--
        
        //optimal solution would be to take smallest and largest elements aternatively based on the value of power
        
        sort(tokens.begin(), tokens.end());
        
        //two pointers left and right for mini and maxi elements
        int l = 0;
        int r = tokens.size()-1;
        
        int ans = 0;    //maximum score
        int score = 0;  //current score
        
        while(l<=r){
            if(power >= tokens[l]){
                //increment score if power>=(token's minimum element)
                //also decrease power's value
                power -= tokens[l];
                score++;
                ans = max(ans, score);
                l++;
            }
            else if(score>=1){
                //decrement score if it is greater than 0
                //also add maximum element's value to power
                score--;
                power += tokens[r];
                r--;
            }
            else{
                //stopping condition if above conditions don't qualify
                //because in this case, it would decrement the score only and will be of no use
                break;
            }
        }
        
        return ans;
    }
};