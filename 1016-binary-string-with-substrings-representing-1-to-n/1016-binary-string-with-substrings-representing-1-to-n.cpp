class Solution {
    string getBinary(int i){
        string ans = "";
        while(i>0){
            ans.insert(0, to_string(i%2));
            i /= 2;
        }
        return ans;
    }
    bool isSubstr(string& s, string& q){
        // int m = s.size();
        // int n = q.size();
        // int flag = 0;
        // for(int i=0;i<m-n+1;i++){
        //     if(s.substr(i, n) == q){
        //         flag = 1;
        //     }
        // }
        // return flag==1;
        return s.find(q) != -1;
    }
public:
    bool queryString(string s, int n) {
        for(int i=1;i<=n;i++){
            string bin = getBinary(i);
            // cout<<bin<<" ";
            if(!isSubstr(s, bin)){
                return false;
            }
        }
        return true;
    }
};