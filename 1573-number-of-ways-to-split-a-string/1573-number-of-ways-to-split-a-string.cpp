class Solution {
    int mod = 1e9+7;
public:
    int numWays(string s) {
        int n = 0;  //total no. of 1's
        for(auto& x : s){
            if(x=='1'){
                n++;
            }
        }
        if(n%3!=0){
            return 0;
        }
        
        if(n==0){
            int x = s.size();
            return (long long)(x-1)*(x-2)/2 % mod;
        }
        
        int ones = n/3;
        int l=0;
        int r=s.size()-1;
        int currCnt = 0;
        while(l<s.size() && currCnt<ones){
            if(s[l]=='1')
                currCnt++;
            l++;
        }
        currCnt = 0;
        while(r>0 && currCnt<ones){
            if(s[r]=='1')
                currCnt++;
            r--;
        }
        
        int ml=l;
        int mr=r;
        while(ml<s.size() && s[ml]=='0')
            ml++;
        while(mr>0 && s[mr]=='0')
            mr--;
    
        cout<<ml<<" "<<mr<<endl;
        cout<<l<<" "<<r<<endl;
    
        // return 1;
        return (long long)(ml-l+1)*(r-mr+1) % mod;
    }
};