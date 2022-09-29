class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        
        priority_queue<int> pq1;    // elements smaller than x
        priority_queue<int, vector<int>, greater<int>> pq2;    // elements greater than x
        
        for(auto num : arr){
            if(num <= x)
                pq1.push(num);
            else
                pq2.push(num);
        }
        
        while(k>0){
            if(!pq1.empty() && !pq2.empty()){
                int a = pq1.top();
                int b = pq2.top();
                if(abs(a-x)==abs(b-x)){
                    ans.insert(ans.begin(),a);
                    pq1.pop();
                }
                else if(abs(a-x)<abs(b-x)){
                    ans.insert(ans.begin(),a);
                    pq1.pop();
                }
                else{
                    ans.push_back(b);
                    pq2.pop();
                }
            }
            else if(!pq1.empty()){
                ans.insert(ans.begin(),pq1.top());
                pq1.pop();
            }
            else if(!pq2.empty()){
                ans.push_back(pq2.top());
                pq2.pop();
            }
            k--;
        }
        
        // sort(ans.begin(), ans.end());
        
        return ans;
    }
};