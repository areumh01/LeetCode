class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==1 && nums[0]==target) return true;
        else if(nums.size()==1 && nums[0]!=target) return false;

        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            while(start<end && nums[start]==nums[start+1]) start++;
            while(start<end && nums[end]==nums[end-1]) end--;

            int mid = (start+end)/2;
            if(nums[mid]==target) return true;
            else if(nums[start]<=nums[mid]){
                if(nums[start]<=target&&target<nums[mid]) end=mid-1;
                else start=mid+1;
            }
            else{
                if(nums[mid]<target&&target<=nums[end]) start=mid+1;
                else end=mid-1;
            }
        }
        return false;

    }
};