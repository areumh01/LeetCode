class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> answer(nums.size(),-100000);
        answer[0] = nums[0];
        int result=nums[0];
        for(int i=1; i<nums.size(); i++){
            answer[i] = max(nums[i],answer[i-1]+nums[i]);
            result = max(result,answer[i]);
        }
        return result;
    }
};