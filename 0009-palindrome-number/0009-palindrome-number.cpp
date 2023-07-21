class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x!=0&&x%10==0) return false;
        int check=0;
        while(x>check){
            check=check*10+x%10;
            x/=10;
        }
        if(x==check||check/10==x) return true;
        else return false;
    }
};