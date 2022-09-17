class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>> hmap;
        for(auto x : trust){
            hmap[x[0]].push_back(x[1]);
        }
        
        int judge = 0;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(!hmap.count(i)){ //judge trust nobody
                judge = i;
                cnt++;
            }
        }
        if(cnt != 1){   //there is only one judge
            return -1;
        }
        
        bool flag = true;
        for(int i=1;i<=n;i++){
            if(i==judge){
                continue;
            }
            bool temp = false;
            for(auto x : hmap[i]){  //every person atleast trusts judge
                if(x == judge){
                    temp = true;
                    break;
                }
            }
            if(temp==false){
                flag = temp;
                break;
            }
        }
        if(flag==true)
            return judge;
        else
            return -1;
    }
};