class Solution {
public:
    vector<string> answer;
    
    void makeparen(string str, int n, int m){
        if(n==0&&m==0) answer.push_back(str);
        
        if(n>0) makeparen(str+"(",n-1,m+1);
        if(m>0) makeparen(str+")",n,m-1);
    }
    
    vector<string> generateParenthesis(int n) {
        makeparen("", n, 0);
        return answer;
    }
};