class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        sort(strs.begin(),strs.end());
        
        for(int i=0; i<strs[0].size(); i++){
            if(strs[0][i] == strs.back()[i]) prefix+=strs[0][i];
            else break;
        }
        return prefix;
    }
};