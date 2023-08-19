class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        bool table[102][102];
        int answer=0;
        memset(table,false,sizeof(table));
        for(auto e : roads){
            table[e[0]][e[1]] = true;
            table[e[1]][e[0]] = true;
        }

        int rowsum[102];
        memset(rowsum,0,sizeof(rowsum));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(table[i][j]) rowsum[i]++;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(table[i][j]) answer = max(answer,rowsum[i]+rowsum[j]-1);
                else answer = max(answer,rowsum[i]+rowsum[j]);
            }
        }
        return answer;
    }
};