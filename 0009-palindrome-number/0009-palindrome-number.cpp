class Solution {
public:
    bool isPalindrome(int x) {
        int length = 1;
        stack<int> s;
        int tmp=x;
        
        if(x<0) return false;
        
        while(true){
            if(tmp/10 == 0) break;
            tmp/=10;
            length++;
        }
        //cout << length;
        
        for(int i=0; i<length/2; i++){
            s.push(x%10);
            x/=10;
        }
        if(length%2==1) x/=10;
        
        while(x!=0){
            if(x%10 == s.top()){
                s.pop();
                x/=10;
            }
            else return false;
        }
        return true;
    }
};