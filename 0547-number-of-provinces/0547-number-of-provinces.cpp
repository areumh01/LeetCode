class Solution {
public:
    void visitall(int node, vector<vector<int>>& graph, vector<bool>& visited){
        visited[node] = true;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int current = q.front();
            q.pop();
            for(auto i=0; i<graph[current].size(); i++){
                if(!visited[graph[current][i]]){
                    visited[graph[current][i]] = true;
                    q.push(graph[current][i]);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<vector<int>> graph(n+2);
        vector<bool> visited(n+2, false);
        int answer=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(isConnected[i][j]==1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        for(int i=0; i<n; i++){
            if(!visited[i]){
                answer++;
                visitall(i, graph,visited);
            }
        }
        return answer;
    }
};