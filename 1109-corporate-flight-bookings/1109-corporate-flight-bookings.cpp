class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> flights(n+2,0);
        
        for(auto x : bookings){
            int first = x[0];
            int last = x[1];
            int cnt = x[2];
            
            //using prefix sum technique
            flights[first] += cnt;
            flights[last+1] -= cnt;
        }
        
        for(int i=1;i<=n+1;i++){
            flights[i] += flights[i-1];
        }
        
        flights.erase(flights.begin());
        flights.erase(flights.end()-1);
        
        //for pictorial representation, refer to the link below
        // https://leetcode.com/problems/corporate-flight-bookings/discuss/328871/C++Java-with-picture-O(n)
        
        return flights;
    }
};