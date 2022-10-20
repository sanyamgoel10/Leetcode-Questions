class Solution {
public:
    string intToRoman(int num) {
        
        //create two arrays mapped with each other in terms of value and roman value
        vector<int> nums {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> rnums {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string res="";
        
        //iterate over the array
        for(int i=0;i<nums.size();i++){
            //add rnum[i] value to the result until nums[i] value is less than num
            while(nums[i]<=num){
                res+=rnums[i];
                num-=nums[i];    //at each step decrease value of num by
            }
        }
        
        return res;
    }
};