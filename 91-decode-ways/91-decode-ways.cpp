class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        int nextNext = 1;
        int next = 0;
        
        for(int i=n-1;i>=0;i--){
            int curr;
            if(s[i]=='0'){
                curr = 0;
            }
            else{
                curr = nextNext;
            }
            
            if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))){
                curr += next;
            }
            next = nextNext;
            nextNext = curr;
        }
        
        return nextNext;
    }
};