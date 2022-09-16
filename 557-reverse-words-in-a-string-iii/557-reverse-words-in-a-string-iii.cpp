class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        
        int ind = 0;
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                reverse(s.begin()+ind, s.end()-n+i);
                ind = i+1;
            }
            if(i==n-1){
                reverse(s.begin()+ind, s.end());
            }
        }
        
        return s;
    }
};