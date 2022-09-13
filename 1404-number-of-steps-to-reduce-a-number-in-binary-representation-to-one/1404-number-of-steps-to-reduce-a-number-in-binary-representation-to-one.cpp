class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;
        
        while(s!="1"){
            int n = s.size();
            if(s[n-1]=='0'){
                //last bit of binary integer is 0, i.e, it is an even number
                //hence change it to its num/2
                //Now, to do this, to convert a number to its half, we basically remove its last digit
                // 6=0110  ->  6/2=3=110
                
                s.pop_back();
            }
            else{
                //last bit is 1, i.e., it is an odd number
                //we add 1 to the number
                
                int i=n-1;
                while(i>=0 && s[i]=='1'){
                    s[i] = '0';
                    i--;
                }
                if(i>=0){
                    s[i] = '1';
                }
                else{
                    s = '1'+s;
                }
            }
            cnt++;
        }
        
        return cnt;
    }
};