//class Solution {
//public:
//    string longestPalindrome(string s) {
//        string answer="";
//        vector<vector<bool>> dp;
//        dp.assign(s.size(), vector<bool>(s.size(),false));
//        
//        if(s.size()==0) return "";
//        for(int len=0; len<s.size(); len++){
//            for(int i=0; i+len<s.size(); i++){
//                int j=i+len;
//                if(s[i]==s[j] && (j<=i+1 || dp[i+1][j-1])){
//                    dp[i][j]=true;
//                    if(j-i+1 > answer.size()) answer = s.substr(i,j-i+1);
//                }
//            }
//        }
//        return answer;
//    }
//};

class Solution {
public:
    string longestPalindrome(string s) {
        string answer="";
        for(int i=0; i<s.size(); i++){
            int right=i;
            while(right<s.size()-1 && s[i] == s[right+1]) right++;
            int left=i;
            while(left>0 && right<s.size()-1 && s[left-1] == s[right+1]){
                left--;
                right++;
            }
            if(answer.size() < right-left+1) answer=s.substr(left,right-left+1);
        }
        
        return answer;
    }
};