class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        
        while(start<end){
            int mid=(start+end)/2;
            if(nums[mid]>=nums.back()) start=mid+1;
            else end=mid;
        }
        
        int inverse = end;
        //cout << inverse << '\n';
        start=0;
        end=nums.size()-1;
        
        while(start<=end){
            int mid=(start+end)/2;
            int pivottedmid=(mid+inverse)%nums.size();
            if(nums[pivottedmid] > target) end = mid-1;
            else if(nums[pivottedmid] < target) start=mid+1;
            else return pivottedmid;
        }
        return -1;
    }
};