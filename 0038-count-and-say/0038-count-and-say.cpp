class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        
        for(int i=2;i<=n;i++){
            string temp = ans;
            ans = "";
            int l=0;
            int r=1;
            while(r<temp.size()){
                if(temp[r]!=temp[l]){
                    ans += to_string(r-l);
                    ans += temp[l];
                    l=r;
                }
                r++;
            }
            ans += to_string(r-l);
            ans += temp[l];
        }
        
        return ans;
    }
};