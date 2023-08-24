class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(n%(i+1)==0){
                string sub = s.substr(0,i+1);
                string repeated = "";
                for(int t=0; t<n/(i+1); t++){
                    repeated+=sub;
                }
                if(repeated == s) return true;
            }
        }
        return false;
    }
};