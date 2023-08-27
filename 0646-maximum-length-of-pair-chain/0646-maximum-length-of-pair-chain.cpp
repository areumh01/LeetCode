class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int dp[2005];
        int k;
        memset(dp,0,sizeof(dp));
        vector<vector<int>> start(2005);
        for(int i=0; i<pairs.size(); i++){
            start[pairs[i][1]+1+1001].push_back(pairs[i][0]+1001);
            k = max(k,pairs[i][1]+1+1001);
        }

        for(int i=1; i<=k; i++){
            dp[i] = dp[i-1];
            if(start[i].size()==0) continue;
            for(int j=0; j<start[i].size(); j++){
                dp[i] = max(dp[i],dp[start[i][j]]+1);
            }
        }
        return dp[k];
    }
};