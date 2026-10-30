class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =  nums.size();
        vector<pair<int , int>> nums1;
        for(int i = 0 ; i < n ; i++){
            nums1.push_back({nums[i] , i});
        }
        sort(nums1.begin() , nums1.end());
        int left = 0;
        int right = nums1.size() - 1;
        while(left < right){
            int sum = nums1[left].first + nums1[right].first;
            if(sum == target)
            return {nums1[left].second , nums1[right].second};
        
            else if(sum < target){
                left++;
            }
            else{
            right--;
            }
        }
        return {};
    }
};