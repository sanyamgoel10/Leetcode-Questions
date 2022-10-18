class Solution {
public:
    int arrangeCoins(int n) {
        int cnt = 0;
        int i = 1;
        while(true){
            if(n-i < 0){
                break;
            }
            n -= i;
            i++;
            cnt++;
        }
        return cnt;
    }
};