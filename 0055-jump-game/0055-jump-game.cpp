class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int jump = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(i<=jump && i+nums[i] > jump) jump = i+nums[i];
            if(jump >= nums.size()-1) return true;
        }
        return false;
    }
};