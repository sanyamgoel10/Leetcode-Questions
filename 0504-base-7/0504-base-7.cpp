class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        
        if(num==0)
            return "0";
        
        if(num<0){
            ans.insert(0,"-");
            num = -num;
            while(num>0){
                ans.insert(1, to_string(num%7));
                num /= 7;
            }
            return ans;
        }
        
        while(num>0){
            ans.insert(0, to_string(num%7));
            num /= 7;
        }
        
        return ans;
    }
};