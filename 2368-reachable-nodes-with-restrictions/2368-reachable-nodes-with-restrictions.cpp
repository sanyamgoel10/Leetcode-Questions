class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        //create an adjacency list of all the nodes
        //add all restricted nodes to unordered_map rest, to find them easily
        //perform bfs traversal starting from 0
        //in bfs traversal, if a node is restricted, dont push it in queue and hence dont take it
        
        unordered_map<int, vector<int>> adj;
        for(auto x : edges){
            int a = x[0];
            int b = x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        unordered_map<int,int> rest;
        for(auto x : restricted){
            rest[x]++;
        }
        
        vector<int> vis(n);
        
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x : adj[node]){
                if(!vis[x] && !rest.count(x)){
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
        
        int ans = 0;
        for(auto x : vis){
            if(x==1)
                ans++;
        }
        
        return ans;
    }
};