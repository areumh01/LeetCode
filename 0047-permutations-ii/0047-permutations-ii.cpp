/*
순열에서 중복되는 애들은 방문하지 않고 뛰어넘기 : set사용
*/

class Solution {
public:
    vector<vector<int>> answer;
    vector<bool> visited;

    void dfs(vector<int>& nums, vector<int>& sub){
        if(sub.size() == nums.size()){
            answer.push_back(sub);
            return;
        }
        set<int> s;
        for(int i=0; i<nums.size(); i++){
            if(!visited[i]){
                if(s.find(nums[i]) != s.end()) continue;
                s.insert(nums[i]);

                visited[i] = true;
                sub.push_back(nums[i]);
                dfs(nums,sub);
                sub.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visited.resize(nums.size());
        vector<int> sub;
        dfs(nums,sub);
        //sort(answer.begin(),answer.end());
        //answer.erase(unique(answer.begin(),answer.end()),answer.end());
        return answer;
    }
};