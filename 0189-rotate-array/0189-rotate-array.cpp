class Solution {
public:
    // 1,2,3,4,5,6,7 -> k=0
    // 7,1,2,3,4,5,6 -> k=1
    // 6,7,1,2,3,4,5 -> k=2
    // 5,6,7,1,2,3,4 -> k=3
    // 4,5,6,7,1,2,3 -> k=4
    // 3,4,5,6,7,1,2 -> k=5
    // 2,3,4,5,6,6,1 -> k=6
    // 1,2,3,4,5,6,7 -> k = 7 = n
    // 7,1,2,3,4,5,6 -> k=8
    // 6,7,1,2,3,4,5 -> k=9
    // 5,6,7,1,2,3,4 -> k=10
    // 4,5,6,7,1,2,3 -> k=11
    // 3,4,5,6,7,1,2 -> k=12
    // 2,3,4,5,6,6,1 -> k=13
    // 1,2,3,4,5,6,7 -> k = 14 = 2n
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        
        vector<int> temp;
        for(int i=n-k;i<n;i++){
            temp.push_back(nums[i]);
        }
        vector<int> temp1;
        for(int i=0;i<n-k;i++){
            temp1.push_back(nums[i]);
        }
        
        int i = 0;
        int j = 0;
        while(i<temp.size()){
            nums[j] = temp[i];
            i++;
            j++;
        }
        i = 0;
        while(i<temp1.size()){
            nums[j] = temp1[i];
            i++;
            j++;
        }
    }
};