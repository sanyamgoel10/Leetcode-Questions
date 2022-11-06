class Solution {
public:
    int findTheWinner(int n, int k) {
        int cnt = 0;
        
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        
        while(q.size()>1){
            int cnt = k;
            while(cnt>1){
                int curr = q.front();
                q.pop();
                q.push(curr);
                cnt--;
            }
            q.pop();
        }
        
        return q.front();
    }
};