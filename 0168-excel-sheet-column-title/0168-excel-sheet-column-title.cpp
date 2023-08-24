class Solution {
public:
    string convertToTitle(int columnNumber) {
        int tmp = columnNumber-1;
        string answer;
        stack<int> s;
        while(true){
            s.push(tmp%26);
            tmp/=26;
            if(tmp==0) break;
            tmp-=1;
            if(tmp/26==0){
                s.push(tmp);
                break;
            }
        }
        while(!s.empty()){
            answer+=('A'+s.top());
            s.pop();
        }
        return answer;
    }
};