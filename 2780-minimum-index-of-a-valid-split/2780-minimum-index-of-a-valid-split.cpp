class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int> m1,m2;
        vector<int> freqArr;
        int dominant = 0;
        
        for(auto e: nums){
            m2[e]++;
        }
        
        for(int i=0; i<nums.size(); i++){
            int x = --m2[nums[i]];
            int y = ++m1[nums[i]];
            if(y*2 > i+1 && x*2 > (nums.size()-i-1) ) return i;
        }
        
        return -1;
    }
};