class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
    
        int sumOfm = 0;
        for(auto& x : rolls){
            sumOfm += x;
        }
        //because mean = (sumOfn+sumOfm)/(m+n)
        int sumOfn = (mean*(m+n)) - sumOfm;
        
        vector<int> ans;
        
        if(sumOfn > 6*n || sumOfn < n){
            return {};
        }
        
        int temp = sumOfn/n;
        for(int i=0;i<n;i++){
            ans.push_back(temp);
        }
        
        int remainder = sumOfn%n;
        for(int i=0;i<remainder;i++){
            ans[i] += 1;
        }
        
        return ans;
    }
};