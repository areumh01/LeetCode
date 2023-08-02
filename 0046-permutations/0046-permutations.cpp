class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> v(nums.size());
        sort(nums.begin(),nums.end());
        do{
            for(int i=0; i<nums.size(); i++) v[i]=nums[i];
            answer.push_back(v);
        }while(next_permutation(nums.begin(),nums.end()));
        return answer;
    }
};