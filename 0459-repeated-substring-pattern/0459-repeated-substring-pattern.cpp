class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=0; i<n/2; i++){
            string sub = s.substr(0,i+1);
            string comp = s.substr(i+1);
            while(comp.find(sub) == 0){
                if(comp.find(sub)+sub.size() == comp.size()) return true;
                comp = comp.substr(comp.find(sub)+sub.size());
            }
        }
        return false;
    }
};