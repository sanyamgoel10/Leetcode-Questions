class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> hmap;
        for(auto x : text){
            hmap[x]++;
        }
        
        int ans = min(hmap['b'], min(hmap['a'], min(hmap['l']/2, min(hmap['o']/2, hmap['n']))));
        
        return ans;
    }
};