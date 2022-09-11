class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int> hmap;
        for(auto x : brokenLetters){
            hmap[x]++;
        }
        
        int n = text.size();
        int cnt = 0;
        int totalWords = 0;
        
        int k = 0;
        for(int i=0;i<n;i++){
            if(text[i]==' ' || i==n-1){
                totalWords++;
                string temp = text.substr(k, i-k+1);
                
                for(auto x : temp){
                    if(hmap.count(x)){
                        cnt++;
                        break;
                    }
                }
                
                k=i;
            }
        }
        
        return totalWords-cnt;
    }
};