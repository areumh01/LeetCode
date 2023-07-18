class Solution {
public:
    void swap(int a, int b, vector<int>& nums){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    
    void quick_sort(vector<int>& nums, int start, int end){
        //1개의 원소만 들어오는 경우에는 진행하지 않음
        if(start >= end) return;
        
        //변수를 선언 - index임에 주의
        int key = start;
        int left = start+1;
        int right = end;
        
        //key를 기준으로 작은값, 큰값을 분류
        while(left<=right){
            while(left <= end && nums[left] <= nums[key]) left++;
            while(right > start && nums[right] >= nums[key]) right--;
            if(left < right) swap(left,right,nums);
            else swap(key,right,nums);
        }
        //나뉘어진 두 분류를 각각 퀵정렬
        quick_sort(nums,start,right-1);
        quick_sort(nums,right+1,end);
    }
    
    void sortColors(vector<int>& nums) {
        quick_sort(nums,0,nums.size()-1);
    }
};