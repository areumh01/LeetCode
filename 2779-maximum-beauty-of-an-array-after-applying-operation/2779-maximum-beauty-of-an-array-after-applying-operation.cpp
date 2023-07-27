class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int all[300005]={0,};
        int minn=300006,maxx=-1;
        int answer=0;
        
        for(int e: nums){
            all[e-k+100000]++;
            all[e+k+100000+1]--;
            minn = min(e-k+100000,minn);
            maxx = max(e+k+100000,maxx);
        }
        
        for(int i=minn; i<=maxx; i++){
            all[i]+=all[i-1];
            answer=max(answer,all[i]);
        }
        
        return answer;
    }
};