class Solution {
    bool isSelfDividing(int n){
        int temp = n;
        while(temp>0){
            int i = temp%10;
            if(i==0){
                return false;
            }
            temp = temp/10;
            if(n%i!=0){
                return false;
            }
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            if(isSelfDividing(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};