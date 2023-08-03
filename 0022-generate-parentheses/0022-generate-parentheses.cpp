class Solution {
public:
    vector<vector<string>> dp{10};
    
    vector<string> generateParenthesis(int n) {
        dp[1] = {"()"};
        for(int i=2; i<=n; i++){
            vector<string> c;
            for(int j=1; j<i; j++){
                vector<string> a = dp[j];
                vector<string> b = dp[i-j];
                if(j==1)
                   for(auto el : b) c.push_back("("+el+")");
                for(auto e : a){
                    for(auto el : b){
                        c.push_back(e+el);
                        c.push_back(el+e);
                    }
                }
            }
            sort(c.begin(),c.end());
            c.erase(unique(c.begin(),c.end()),c.end());
            dp[i]=c;
        }
        return dp[n];
    }
};