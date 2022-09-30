class Solution {
public:
    string reformatDate(string date) {
        int n = date.size();
        string ans = "";
        
        unordered_map<string,string> months = {{"Jan","01"}, {"Feb","02"}, {"Mar","03"}, {"Apr","04"}, {"May","05"}, {"Jun","06"}, {"Jul","07"}, {"Aug","08"}, {"Sep","09"}, {"Oct","10"}, {"Nov","11"}, {"Dec","12"}};
        
        int i = n-1;
        while(date[i]!=' '){
            i--;
        }
        ans += date.substr(i+1, n-1-i+1);
        ans += "-";
        
        i--;
        int j = i;
        while(date[i]!=' '){
            i--;
        }
        string temp = date.substr(i+1, j-i);
        ans += months[temp];
        ans += "-";
        
        temp = date.substr(0, i-2);
        if(temp.size()==1)
            ans += "0";
        ans += date.substr(0, i-2);
        
        return ans;
    }
};