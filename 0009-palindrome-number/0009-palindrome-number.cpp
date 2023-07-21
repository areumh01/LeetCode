class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string tmp=s;
        reverse(s.begin(),s.end());
        if(s==tmp) return true;
        else return false;
    }
};