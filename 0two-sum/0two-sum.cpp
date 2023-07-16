class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(m[target-nums[i]]>0){
                int index = find(nums.begin(),nums.end(),target-nums[i])-nums.begin();
                if(index == i) continue;
                else return {i,index};
            }
        }
        return {};
    }
};