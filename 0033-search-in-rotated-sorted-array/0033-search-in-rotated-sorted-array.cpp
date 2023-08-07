class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = find(nums.begin(),nums.end(),target)-nums.begin();
        if(n>=0 && n<nums.size()) return n;
        else return -1;
    }
};