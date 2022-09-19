class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();
        vector<vector<string>> ans;
        map<string, vector<string>> hmap;
        
        for(auto address : paths){
            int ind = 0;
            while(ind<address.size() && address[ind]!=' '){
                ind++;
            }
            string dir = address.substr(0, ind);
            dir = dir + "/";
            // cout<<dir<<" : ";
            
            int cnt = ind+1;
            for(int i=ind+1; i<address.size(); i++){
                if(address[i]==' '){
                    string temp = address.substr(cnt, i-cnt);
                    // cout<<temp<<",";
                    
                    int l = temp.find('('); //find (
                    int r = temp.size()-1;  //find )
                    string content = temp.substr(l+1, r-l+1);
                    string file = temp.substr(0,l);
                    hmap[content].push_back(dir+file);
                    
                    cnt = i+1;
                }
            }
            string temp = address.substr(cnt, address.size()-cnt);
            // cout<<temp<<",";
            int l = temp.find('('); //find (
            int r = temp.size()-1;  //find )
            string content = temp.substr(l+1, r-l+1);
            string file = temp.substr(0,l);
            hmap[content].push_back(dir+file);
            
            // cout<<endl;
        }
        
        // for(auto x : hmap){
        //     cout<<x.first<<" : ";
        //     for(auto y : x.second){
        //         cout<<y<<",";
        //     }
        //     cout<<endl;
        // }

        
        for(auto x : hmap){
            if(x.second.size()>1){
                ans.push_back(x.second);
            }
        }
        
        return ans;
    }
};