class Solution {
public:
    vector<vector<int>> answer;

    void find_answer(vector<int>& candidates, int target, int index, vector<int> result){
        if(target == 0) {
            answer.push_back(result);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            vector<int> tmp = result;
            tmp.push_back(candidates[i]);
            if(target >= candidates[i])
                find_answer(candidates, target-candidates[i], i+1, tmp);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        //for(auto e : candidates) cout << e << " ";
        vector<int> visited;
        find_answer(candidates, target, 0, visited);
        sort(answer.begin(),answer.end());
        answer.erase(unique(answer.begin(), answer.end()), answer.end());
        return answer;
    }
};