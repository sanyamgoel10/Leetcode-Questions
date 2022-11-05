class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> even;
        priority_queue<int> odd;
        
        string s = to_string(num);
        int n = s.size();
        for(int i=0;i<n;i++){
            if((s[i]-'0') % 2 != 0)
                odd.push(s[i]-'0');
            else
                even.push(s[i]-'0');
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans *= 10;
            if((s[i]-'0') % 2 != 0){
                ans += odd.top();
                odd.pop();
            }
            else{
                ans += even.top();
                even.pop();
            }
        }
        
        return ans;
    }
};