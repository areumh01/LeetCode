class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool flag = false;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                int number;
                for(int j=nums.size()-1; j>i; j--){
                    if(nums[i] < nums[j]){
                        number = nums[j];
                        nums[j] = nums[i];
                        nums[i] = number;
                        break;
                    }
                }
                sort(nums.begin()+i+1, nums.end());
                flag = true;
                break;
            }
        }
        if(!flag) sort(nums.begin(),nums.end());
    }
};