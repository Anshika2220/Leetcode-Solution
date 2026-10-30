class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maximum1s = 0;
        int zeroes = 0;
        int l = 0;
        for(int r = 0 ; r < nums.size() ; r++){
            if(nums[r] == 0)
             zeroes++;
             while(zeroes > k){
                if(nums[l] == 0){
                 zeroes--;
                }
                l++;
             }
             maximum1s = max(maximum1s , r-l+1);
        }
        return maximum1s;
    }
};