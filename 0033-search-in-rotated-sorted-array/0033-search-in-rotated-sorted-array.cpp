class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            int mid = (start+end)/2;
            if(nums[mid]>nums.back()) start=mid+1;
            else end=mid;
        }
        int last = end;
        start=0;
        end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            int realmid = (mid+last)%nums.size();
            if(nums[realmid]<target) start=mid+1;
            else if(nums[realmid]>target) end=mid-1;
            else return realmid;
        }
        return -1;
    }
};