class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff=1e8;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int left=i+1;
            int right=nums.size()-1;
            
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                int subdiff = target-sum;
                diff = abs(diff) < abs(subdiff)? diff:subdiff;
                if(subdiff<0) right--;
                else if(subdiff>0) left++;
                else break;
            }
        }
        
        return target-diff;
    }
};