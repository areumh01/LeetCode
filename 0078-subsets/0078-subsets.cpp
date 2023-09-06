class Solution {
public:
    vector<vector<vector<int>>> answer;

    void find_subset(int index, vector<int>& nums, vector<int>sub){
        answer[sub.size()].push_back(sub);
        if(index>=nums.size()) return;
        for(int i=index; i<nums.size(); i++){
            vector<int> tmp=sub;
            tmp.push_back(nums[i]);
            find_subset(i+1,nums,tmp);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        answer.resize(nums.size()+1);
        find_subset(0,nums,{});
        vector<vector<int>> result;
        for(int i=0; i<=nums.size(); i++){
            for(int j=0; j<answer[i].size(); j++){
                result.push_back(answer[i][j]);
            }
        }
        return result;
    }
};