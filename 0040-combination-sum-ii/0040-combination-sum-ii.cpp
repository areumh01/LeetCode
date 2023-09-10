class Solution {
public:
    vector<vector<int>> answer;

    void dfs(vector<int>& candidates, int target, int counting, int index, vector<int> sub){
        if(target == counting){
            answer.push_back(sub);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(counting+candidates[i] > target) continue;
            vector<int> tmp = sub;
            tmp.push_back(candidates[i]);
            dfs(candidates,target,counting+candidates[i], i+1, tmp);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates,target,0,0,{});
        return answer;
    }
};