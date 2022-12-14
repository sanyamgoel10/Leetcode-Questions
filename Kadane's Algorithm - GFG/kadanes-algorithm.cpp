//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        int max_ending_here = 0;
        int max_so_far = INT_MIN;
        
        for(int i=0;i<n;i++){
            max_ending_here += arr[i];
            // at every point check if current_maximum is greater than global_max
            if(max_ending_here > max_so_far){
                //update global maximum if current_maximum is found to be greater than it
                max_so_far = max_ending_here;
            }
            if(max_ending_here < 0){
                //update current_maximum if it if found to be smaller than it initialized value
                max_ending_here = 0;
            }
        }
        return max_so_far;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends