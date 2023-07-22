class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i=1; i<strs.size(); i++){
            string tmp="";
            for(int j=0; j<prefix.size(); j++){
                if(prefix[j]==strs[i][j]) tmp+= prefix[j];
                else break;
            }
            prefix=tmp;
        }
        return prefix;
    }
};