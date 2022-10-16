class Solution {
    static bool cmp(vector<int> a, vector<int> b){
        return a[0]<b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]);
        
        int i = 1;
        while(i<n){
            if(ans[ans.size()-1][1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
            }
            i++;
        }
        
        return ans;
    }
};