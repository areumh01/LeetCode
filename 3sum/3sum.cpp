class Solution {
public:
   // vector<vector<int>> find_twosum(int index, int target, vector<int>& nums){
   //     int start = index;
   //     int end = nums.size()-1;
   //     vector<int> tmp;
   //     vector<vector<int>> result;
   //     
   //     while(start<end){
   //         if(nums[start]+nums[end] < target) start++;
   //         else if(nums[start]+nums[end] > target) end--;
   //         else{
   //             tmp = {nums[start],nums[end]};
   //             result.push_back(tmp);
   //             start++;
   //             end--;
   //         }
   //     }
   //     return result;
   // };
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(),nums.end());
        
        if(nums[0]==0 && nums.back()==0) return {{0,0,0}};
        if(nums[0] > 0) return {};
        
        for(int i=0; i<nums.size(); i++){
            int first = nums[i];
            int target = -first;
            //vector<vector<int>> a = find_twosum(i+1,target, nums);
            
            int start = i+1;
            int end = nums.size()-1;
            vector<int> tmp;
            vector<vector<int>> result;
        
            while(start<end){
                if(nums[start]+nums[end] < target) start++;
                else if(nums[start]+nums[end] > target) end--;
                else{
                    tmp = {nums[start],nums[end]};
                    result.push_back(tmp);
                    start++;
                    end--;
                }
            }
            
            if(result.size()!=0){
                for(auto e : result){
                    e.push_back(first);
                    sort(e.begin(),e.end());
                    answer.push_back(e);
                }
            }
        }
        
        sort(answer.begin(),answer.end());
        answer.erase(unique(answer.begin(),answer.end()),answer.end());
        return answer;
    }
};