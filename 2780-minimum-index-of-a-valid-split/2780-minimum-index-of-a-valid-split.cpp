class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int> m;
        vector<int> freqArr;
        int dominant = 0;
        
        for(auto e: nums){
            m[e]++;
            if(m[dominant] < m[e]) dominant = e;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == dominant) freqArr.push_back(i);
        }
        
        for(int i=1; i<=freqArr.size(); i++){
            if(freqArr[i-1]+1<i*2)
                if(nums.size()-(freqArr[i-1]+1) < (freqArr.size()-i)*2)
                    return freqArr[i-1];
        }
        return -1;
    }
};