class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff=1e8;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int newTarget = target-nums[i];
            
            int left=i+1;
            int right=nums.size()-1;
            
            while(left<right){
                int sum = nums[left]+nums[right];
                int subdiff = newTarget-sum;
                diff = abs(diff) < abs(target-sum-nums[i])? diff:target-sum-nums[i];
                if(subdiff<0) right--;
                else if(subdiff>0) left++;
                else break;
            }
        }
        
        return target-diff;
    }
};