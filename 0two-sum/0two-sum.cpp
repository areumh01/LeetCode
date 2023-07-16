class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]] = i+1;
        }
        
        for(int i=0; i<nums.size(); i++){
            int another = target-nums[i];
            if(m[another]!=0 && m[another]!=i+1){
                return {i,m[another]-1};
            }
        }
        return {};
    }
};