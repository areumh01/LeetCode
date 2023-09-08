class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        answer.push_back({1});

        for(int i=1; i<numRows; i++){
            vector<int> sub(i+1);
            for(int j=0; j<sub.size(); j++){
                if(j==0) sub[j]=1;
                else if(j==sub.size()-1) sub[j]=1;
                else sub[j] = answer[i-1][j-1]+answer[i-1][j];
            }
            answer.push_back(sub);
        }
        return answer;
    }
};