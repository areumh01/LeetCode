class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int comp[2002];
        int fq[2002];
        int lsi=0;
        int answer=0;
        
        for(int i=0;i<nums.size();i++){
            comp[i]=1;
            fq[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(comp[j]==comp[i]){
                        comp[i]=comp[j]+1;
                        fq[i]=fq[j];
                    }
                    else if(comp[j]+1==comp[i]) fq[i]+=fq[j];
                }
            }
            lsi=max(lsi,comp[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(comp[i]==lsi) answer+=fq[i];
        }
        
        return answer;
    }
};