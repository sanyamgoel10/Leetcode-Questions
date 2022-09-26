class Solution {
    void dfs(int i, int color, unordered_map<int, vector<int>>& equals, vector<int>& vis, vector<int>& nodeColor){
        //mark i as 1, and assign it color
        vis[i] = 1;
        nodeColor[i] = color;
        for(auto neighbor : equals[i]){
            if(!vis[neighbor]){
                dfs(neighbor, color, equals, vis, nodeColor);
            }
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map<int, vector<int>> equals;
        for(auto x : equations){
            int a = x[0] - 'a';
            int b = x[3] - 'a';
            if(x[1] == '='){
                equals[a].push_back(b);
                equals[b].push_back(a);
            }
        }
        
        vector<int> vis(26);
        vector<int> nodeColor(26);  //keep track of which node has which color
        
        int color = 0;  //assign color 0 to 1st node
        
        for(int i=0;i<26;i++){
            if(!vis[i]){
                dfs(i, color, equals, vis, nodeColor);
            }
            color++;    //assign new color to next node
        }
        
        for(auto x : equations){
            int a = x[0] - 'a';
            int b = x[3] - 'a';
            if(x[1] == '!' && nodeColor[a]==nodeColor[b]){
                //because both nodes cannot be of same color, but we have already colored them as same
                return false;
            }
        }
        
        return true;
    }
};