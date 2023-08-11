class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> answer(target+2);

        for(int i=0; i<candidates.size(); i++){
            //2, 3, 6, 7
            for(int j=1; j<=target; j++){
                //0,1,2,3,4,5,6,7
                if(j>=candidates[i]){
                    for(auto e:answer[j-candidates[i]]){
                        vector<int> tmp = e;
                        tmp.push_back(candidates[i]);
                        answer[j].push_back(tmp);
                    }
                    if(j==candidates[i]) answer[j].push_back({candidates[i]});
                }
            }
        }
        return answer[target];
    }
};