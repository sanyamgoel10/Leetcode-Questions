class Solution {
    static bool comp(string s1, string s2){
        return s1.size()<=s2.size();
    }
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        vector<int> hash(26,0);
        for(auto x : licensePlate){
            if((x>='a' && x<='z') || (x>='A' && x<='Z')){
                x = tolower(x);
                hash[x-'a']++;                
            }
        }
        
        // for(auto x : hash){
        //     cout<<x<<" ";
        // }
        // cout<<endl<<endl;
        
        vector<string> temp;
        
        for(string x : words){
            vector<int> hash1(26,0);
            for(char y : x){
                if((y>='a' && y<='z') || (y>='A' && y<='Z')){
                    y = tolower(y);
                    hash1[y-'a']++;                
                }
            }
            // for(auto l : hash1){
            //     cout<<l<<" ";
            // }
            // cout<<endl;
            int cnt=0;
            for(int i=0;i<hash.size();i++){
                if(hash1[i]>=hash[i]){
                    cnt++;
                }
            }
            if(cnt==26){
                temp.push_back(x);
            }
        }
        
        // for(auto x : temp){
        //     cout<<x<<" ";
        // }
        
        string ans = temp[0];
        for(auto x : temp){
            if(x.size()<ans.size()){
                ans = x;
            }
        }
        
        return ans;
    }
};