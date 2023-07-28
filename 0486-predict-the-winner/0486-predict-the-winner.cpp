class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size()+2, 0));
        
        for(int len=0; len<nums.size(); len++){
            for(int i=0; i+len<nums.size(); i++){
                int j = i+len;
                if(i==j) dp[i][j] = nums[i];
                else dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        
        return dp[0][nums.size()-1] >= 0;
    }
};