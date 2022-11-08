class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<char,pair<int,int>> hmap;
        for(int i=0;i<26;i++){
            hmap[i+'a'] = {i/5,i%5};
        }
        
        target = 'a' + target;  //starting position
        string ans = "";
        
        for(int i=1;i<target.size();i++){
            int curr = target[i];
            int prev = target[i-1];
            
            int currX = hmap[curr].first;
            int currY = hmap[curr].second;
            int prevX = hmap[prev].first;
            int prevY = hmap[prev].second;
            
            int x = currX-prevX;
            int y = currY-prevY;
            
            if(y < 0){
                //we have to go x steps to the left
                for(int j=0;j<abs(y);j++){
                    ans += 'L';
                }
            }
            if(x < 0){
                //we have to go y steps to the up
                for(int j=0;j<abs(x);j++){
                    ans += 'U';
                }
            }
            if(y > 0){
                //we have to go x steps to the right
                for(int j=0;j<y;j++){
                    ans += 'R';
                }
            }
            if(x > 0){
                //we have to go y steps to the down
                for(int j=0;j<x;j++){
                    ans += 'D';
                }
            }
            
            ans += "!";
        }
        
        return ans;
    }
};