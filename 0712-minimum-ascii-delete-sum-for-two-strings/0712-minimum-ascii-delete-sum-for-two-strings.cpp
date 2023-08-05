class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> all(s1.size()+1,vector<int>(s2.size()+1));
        int answer=0;
        for(int i=1; i<=s1.size(); i++){
            for(int j=1; j<=s2.size(); j++){
                if(s1[i-1]==s2[j-1])
                    all[i][j] = all[i-1][j-1]+s1[i-1];
                else
                    all[i][j] = max(all[i-1][j], all[i][j-1]);
            }
        }
        
        for(auto e:s1) answer+=e;
        for(auto e:s2) answer+=e;
        return answer-2*all[s1.size()][s2.size()];
    }
};