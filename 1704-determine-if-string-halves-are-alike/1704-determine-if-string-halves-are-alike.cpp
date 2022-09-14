class Solution {
    bool isVowel(char& a){
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='A' || a=='E' || a=='I' || a=='O' || a=='U'){
            return true;
        }
        return false;
    }
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        
        int c1 = 0;
        int c2 = 0;
        
        int i=0;
        for(i;i<n/2;i++){
            if(isVowel(s[i]))
                c1++;
        }
        for(i;i<n;i++){
            if(isVowel(s[i]))
                c2++;
        }
        
        return c1==c2;
    }
};