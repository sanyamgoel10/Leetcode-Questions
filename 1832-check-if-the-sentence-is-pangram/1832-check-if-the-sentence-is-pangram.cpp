class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> hmap;
        for(char i='a'; i<='z'; i++){
            hmap[i] = 1;
        }
        unordered_map<char,int> hmap1;
        for(int i=0;i<sentence.size();i++){
            hmap1[sentence[i]] = 1;
        }
        return hmap==hmap1;
    }
};