class Solution {
public:
    vector<vector<int>> answer;
    int N,K;
    
    void make_comb(int index, int counting, vector<int> nums){
        for(int i=index+1; i<=N; i++){
            vector<int> tmp = nums;
            tmp.push_back(i);
            if(counting == K-1) answer.push_back(tmp);
            else make_comb(i, counting+1, tmp);
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        N=n;
        K=k;
        make_comb(0,0,{});
        return answer;
    }
};