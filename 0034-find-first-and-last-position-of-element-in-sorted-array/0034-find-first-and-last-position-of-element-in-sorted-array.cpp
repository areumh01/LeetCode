class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        if(find(nums.begin(),nums.end(),target)-nums.begin()>=nums.size()) return {-1,-1};
        
        vector<int> answer(2);
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]<=target) start=mid+1;
            else end=mid-1;
        }
        if(nums[end]==target)
            answer[1] = end;
        else
            answer[1] = -1;
        
        start=0;
        end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]<target) start=mid+1;
            else end=mid-1;
        }
        if(nums[start]==target)
            answer[0]=start;
        else
            answer[0]=-1;
        
        return answer;
    }
};