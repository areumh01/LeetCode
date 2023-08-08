class Solution {
public:
    int bs(int start, int end, vector<int>& nums, int target){
        int mid = (start+end)/2;
        while(start<=end){
            mid = (start+end)/2;
            if(nums[mid]<target) start = mid+1;
            else if(nums[mid]>target) end = mid-1;
            else break;
        }
        if(nums[mid]==target) return mid;
        else return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums[0]<nums.back()) return bs(0,nums.size()-1,nums,target);
        int start =0;
        int end = nums.size()-1;
        while(start<end-1){
            int mid = (start+end)/2;
            if(nums[start] < nums[mid]) start = mid;
            else if(nums[end] > nums[mid]) end = mid;
        }
        if(target >= nums[0]) return bs(0, start, nums, target);
        else return bs(start+1, nums.size()-1, nums, target);
    }
};