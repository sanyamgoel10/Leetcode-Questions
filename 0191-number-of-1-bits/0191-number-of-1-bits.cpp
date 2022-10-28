class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n>0){
            ans += n&1; //find if last bit is 1 or not and increase count if present
            n = n>>1;   //right shift the number by 1 digit to remove ther last 1
        }
        return ans;
    }
};