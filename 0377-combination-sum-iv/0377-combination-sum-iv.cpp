class Solution {
public:    
    unsigned int memo[1005];

    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        memset(memo,0,sizeof(memo));
        memo[0] = 1;
        for(int i=1; i<=target; i++){
            for(int j=0; j<nums.size(); j++){
                if(i>=nums[j])
                    memo[i] += memo[i-nums[j]];
            }
        }
        return memo[target];
    }
};