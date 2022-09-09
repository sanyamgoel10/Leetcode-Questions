class Solution {
    static bool comp(vector<int>& temp1, vector<int>& temp2){
        if(temp1[0]!=temp2[0]){
            return temp1[0]>temp2[0]; 
        }
        return temp1[1]<temp2[1];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        int n = properties.size();
        int cnt = 0;
        
        //sort the array based on first element and in decreasing order
        sort(properties.begin(), properties.end(), comp);
        
        //maxi is maximum value till now while traversing from right to left
        int maxi = INT_MIN;
        
        for(auto p : properties){
            if(p[1] < maxi){
                //if second parameter is also less than maxi increase the count
                cnt++;
            }
            else{
                //updating the maximum value for 2nd variable at every step
                maxi = p[1];
            }
        }
        
        return cnt;
    }
};