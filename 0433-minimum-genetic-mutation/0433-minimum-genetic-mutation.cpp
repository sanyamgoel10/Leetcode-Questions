class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        //store all valid strings in an unordered set to find any string in O(1) time
        unordered_set<string> hmap;
        for(auto x : bank){
            hmap.insert(x);
        }
        
        //if end string not present in hmap, return -1
        if(hmap.find(end) == hmap.end())
            return -1;
        
        //create a vector to find all valid characters, i.e, only 8 characters available
        vector<int> characters = {'A','C','G','T'};
        
        //to check if current word is already visited or not
        unordered_set<string> vis;
        
        int ans = 0;
        
        //perform BFS operation at not equal index
        //and try to put every valid character on it and check its availability in hmap
        queue<string> q;
        q.push(start);
        vis.insert(start);
        while(!q.empty()){
            int qsize = q.size();   //queue's current size
            
            for(int k=0;k<qsize;k++){
                string curr = q.front();    //current word
                q.pop();    //pop current word from queue
                
                if(curr == end){
                    //break the loop and return the answer
                    return ans;
                }
                
                //now check for every possible mutation of current word
                for(int i=0;i<8;i++){
                    //for every index of current word
                    //try to replace every available character
                    char temp = curr[i];
                    
                    for(int j=0;j<4;j++){
                        curr[i] = characters[j];
                        
                        if(hmap.find(curr)!=hmap.end()){
                            //changed mutation word present in hmap
                            if(vis.find(curr)==vis.end()){
                                //also changed mutation of curr not visited earlier
                                q.push(curr);
                                vis.insert(curr);
                            }
                        }
                    }
                    
                    //rollback the changes in the curr, to check for next step
                    curr[i] = temp;
                }
            }
            ans++;
        }
        
        return -1;  //we didn't reach the end mutation
    }
};