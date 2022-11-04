class Solution {
    bool isVowel(char& a){
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='A' || a=='E' || a=='I' || a=='O' || a=='U'){
            return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        
        while(i<=j){
            if(isVowel(s[i]) && isVowel(s[j])){
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
            else if(isVowel(s[i])){
                while(!isVowel(s[j])){
                    j--;
                }
            }
            else if(isVowel(s[j])){
                while(!isVowel(s[i])){
                    i++;
                }
            }
            else{
                i++;
                j--;
            }
        }
        
        return s;
    }
};