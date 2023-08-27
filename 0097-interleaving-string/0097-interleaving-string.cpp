class Solution {
public:
    bool answer[102][102];
    int visited[102][102];

    bool dfs(int index1, int index2, string& s1, string& s2, string& s3){
        if(index1+index2 == s3.size()) return answer[index1][index2] = true;
        if(visited[index1][index2]) return answer[index1][index2];
        int tmp = false;
        visited[index1][index2] = true;
        if(s1[index1] == s3[index1+index2])
            tmp = (tmp || dfs(index1+1, index2, s1,s2,s3));
        if(s2[index2] == s3[index1+index2])
            tmp = (tmp || dfs(index1, index2+1, s1,s2,s3));
        return answer[index1][index2] = tmp;
    }

    bool isInterleave(string s1, string s2, string s3) {
        memset(visited,false,sizeof(answer));
        dfs(0,0,s1,s2,s3);
        return answer[s1.size()][s2.size()];
    }
};