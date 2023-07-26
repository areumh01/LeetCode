class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(),usageLimits.end());
        long long sum=0;
        long long answer=0;
        for(int i=0; i<usageLimits.size(); i++){
            sum+=usageLimits[i];
            if(sum >= (answer+1)*(answer+2)/2) answer++;
        }
        
        return answer;
    }
};