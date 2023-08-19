class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,-1,1};
        vector<vector<int>> answer(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0) q.push({i,j});
                else answer[i][j] = 1e8;
            }
        }
        while(!q.empty()){
            pair<int,int> current = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nextx = current.first+x[i];
                int nexty = current.second+y[i];
                if(nextx>=0&&nextx<n&&nexty>=0&&nexty<m){
                    if(answer[nextx][nexty] > answer[current.first][current.second]+1){
                        answer[nextx][nexty] = answer[current.first][current.second]+1;
                        q.push({nextx,nexty});
                    }
                }
            }
        }
        return answer;
    }
};