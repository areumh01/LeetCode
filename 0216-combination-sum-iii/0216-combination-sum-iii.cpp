class Solution {
public:
    vector<vector<int>> answer;
    //bool visited[10];

    void dfs(int k, int n, int counting, int index, vector<int> sub){
        if(sub.size() == k && counting == n){
            answer.push_back(sub);
            return;
        }
        for(int i=index; i<10; i++){
            if(sub.size() < k && counting+i <= n){
                //visited[i] = true;
                vector<int> tmp = sub;
                tmp.push_back(i);
                dfs(k,n,counting+i,i+1,tmp);
                //visited[i] = false;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        //memset(visited,false,sizeof(visited));
        dfs(k,n,0,1,{});
        return answer;
    }
};