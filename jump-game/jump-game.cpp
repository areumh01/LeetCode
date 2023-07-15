class Solution {
public:
    bool pos[10002];
    bool answer = false;
    
    bool canJump(vector<int>& nums) {
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] >= nums.size()-1-i){
                pos[i] = true;
            }
            else{
                for(int j=0; j<=nums[i]; j++){
                    if(pos[i+j]){
                        pos[i] = true;
                        break;
                    }
                }
            }
        }
        if(nums.size() == 1) answer = true;
        else if(pos[0]) answer = true;
        return answer;
    }
};