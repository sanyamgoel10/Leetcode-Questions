class Solution {
    int solve(int& start, string& dir, string& file, string& content, string& s){
        int l = start;
        int r = s.size();
        
        //getting current directory
        while(l<r && s[l]!=' '){
            dir += s[l];
            l++;
        }
        l++;
        
        //getting current file
        while(l<r && s[l]!='('){
            file += s[l];
            l++;
        }
        l++;
        
        //getting content value
        while(l<r && s[l]!=')'){
            content += s[l];
            l++;
        }
        
        start = l;  //updating start's location to get file and contents of same directory if present
        return l;
    }
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();
        vector<vector<string>> ans;
        
        unordered_map<string, vector<string>> hmap;
        
        for(int i=0;i<n;i++){
            string curr = paths[i];
            
            string content = "";
            string file = "";
            string dir = "";
            int start = 0;
            while(solve(start, dir, file, content, curr) <= curr.size()){
                hmap[content].push_back(dir + "/" + file);
                content = "";
                file = "";
                start++;
            }
        }
        
        for(auto x : hmap){
            if(x.second.size()>1){
                ans.push_back(x.second);
            }
        }
        
        return ans;
    }
};