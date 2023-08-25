/*
*dfs로 사고 넘기고 안사고 넘기고로 해서 빠져나오면 더이상 살 방법 없으니까 answer에 큰 값 저장
시작 위치가 따로 안정해져있기 때문에 모든 점에서 시작한다면 시간 초과..
*pq에 다 넣고 금값이 높은 것부터 꺼내면서 graph에서 갈 수 있는 위치 확인해서 가기
꼭 그 다음집부터 시작하지 않아도돼서 틀리네 그 다음집보다 크기만 하면 되는데... // 그래서 이중 for문으로 했더니 시간 초과....
*graph만들기, pq만들기, pq의 푸시 조건 = 갈 수 있는 위치가 존재할때 -> 항상 뒤로 가기때문에 무한루프에 빠질 일은 없음

    ^
    |
시간 초과로 틀린 풀이



*/

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> result(n+2,0);
        vector<vector<vector<int>>> m(n+2);
        int answer=0;
        for(auto e: offers){
            m[e[1]+1].push_back(e);
        }
        for(int i=1; i<=n+1; i++){
            result[i] = result[i-1];
            for(int j=0; j<m[i].size(); j++){
                result[i] = max(result[i], result[m[i][j][0]]+m[i][j][2]);
            }
        }

        return result[n+1];
    }
};