class Solution {
public:
    string longestPalindrome(string s) {
        string answer="";
        vector<vector<bool>> dp;
        dp.assign(s.size(), vector<bool>(s.size(),false));
        
        if(s.size()==0) return "";
        for(int len=0; len<s.size(); len++){
            for(int i=0; i+len<s.size(); i++){
                int j=i+len;
                if(i==j) dp[i][j]=true;
                else if(s[i]==s[j]){
                    if(len==1) dp[i][j]=true;
                    else{
                        if(dp[i+1][j-1]) dp[i][j]=true;
                        else dp[i][j]=false;
                    }
                }
                else dp[i][j]=false;
            }
        }
        
        for(int i=0; i<dp.size(); i++){
            for(int j=i; j<dp.size(); j++){
                if(dp[i][j]){
                    if(j-i+1 > answer.size()) answer = s.substr(i,j-i+1);
                }
            }
        }
        
        return answer;
    }
};