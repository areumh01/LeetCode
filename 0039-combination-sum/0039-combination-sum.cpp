class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> answer(target+2);
        sort(candidates.begin(), candidates.end());
        for(int i=0; i<candidates.size(); i++){
            for(int j=1; j<=target; j++){
                if(j==candidates[i]) answer[j].push_back({j});
                else if(j>=candidates[i] && answer[j-candidates[i]].size()!=0){
                    for(auto e : answer[j-candidates[i]]){
                        vector<int> tmp = e;
                        tmp.push_back(candidates[i]);
                        answer[j].push_back(tmp);
                    }
                }
            }
        }
        return answer[target];
    }
};