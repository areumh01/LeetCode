//class Solution {
//public:
//    int minAbsoluteDifference(vector<int>& nums, int x) {
//        int dp[100002];
//        memset(dp,-1,sizeof(dp));
//        for(int d=x; d<nums.size(); d++){
//            for(int tx=1; tx+d<=nums.size(); tx++){
//                int ty = tx+d;
//                if(dp[ty]==-1) dp[ty] = abs(nums[tx-1]-nums[ty-1]);
//                else dp[ty] = min(dp[ty],abs(nums[tx-1]-nums[ty-1]));
//                for(int mid=tx+x; mid<=ty; mid++){
//                    dp[ty] = min(dp[ty], dp[mid]);
//                }
//            }
//        }
//        return dp[nums.size()];
//    }
//};

class Solution {
public: 
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> s;
        int answer = INT_MAX;
        for(int i=x; i<nums.size(); i++){
            s.insert(nums[i-x]);
            auto it = s.upper_bound(nums[i]);
            if(it!=s.end()) answer = min(answer,abs(nums[i]-*it));
            if(it!=s.begin()) answer = min(answer,abs(nums[i]-*prev(it)));
       }
       return answer;
    }
};