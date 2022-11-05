class Solution {
    static bool cmp(int& a, int& b){
        return a>b;
    }
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        // even -> increasing
        // odd -> decreasing
        
        int n = nums.size();
        
        //store even and odd indexed integers in two arrays
        vector<int> inc, dec;
        for(int i=0;i<n;i++){
            if(i%2==0)
                inc.push_back(nums[i]);
            else
                dec.push_back(nums[i]);
        }
        
        //sort both arrays in increasing and decreasing order
        sort(inc.begin(), inc.end());
        sort(dec.begin(), dec.end(), cmp);
        
        //put the values back to nums
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i] = inc[a];
                a++;
            }
            else{
                nums[i] = dec[b];
                b++;
            }
        }
        
        return nums;
    }
};