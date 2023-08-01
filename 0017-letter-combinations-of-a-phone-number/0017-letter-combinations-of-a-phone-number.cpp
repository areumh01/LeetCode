class Solution {
public:
    vector<string> answer;
    
    void dfs(int index, int counting, string& subs, string& s){
        int num = (s[index]-'0');

        if(num>=2 && num<=6){
            num = 3*(num-2);
            for(int i=0; i<3; i++){
                string tmp = subs;
                tmp+=('a'+num+i);
                if(counting == s.size()-1) answer.push_back(tmp);
                else dfs(index+1, counting+1, tmp, s);
            }
        }
        else{
            if(num==7 || num==9){
                if(num==7) num=15;
                if(num==9) num=22;
                for(int i=0; i<4; i++){
                    string tmp = subs;
                    tmp+=('a'+num+i);
                    if(counting == s.size()-1) answer.push_back(tmp);
                    else dfs(index+1, counting+1, tmp, s);
                }
            }
            else{
                num=19;
                for(int i=0; i<3; i++){
                    string tmp = subs;
                    tmp+=('a'+num+i);
                    if(counting == s.size()-1) answer.push_back(tmp);
                    else dfs(index+1, counting+1, tmp, s);
                }
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        
        string s = "";
        dfs(0,0,s,digits);
        
        return answer;
    }
};