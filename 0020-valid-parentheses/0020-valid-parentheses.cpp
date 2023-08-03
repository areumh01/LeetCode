class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(auto e:str){
            if(e=='(' || e=='{' || e=='[') s.push(e);
            else if(s.empty()) return false;
            else if(e==')'){
                if(s.top()=='(') s.pop();
                else return false;
            }
            else if(e=='}'){
                if(s.top()=='{') s.pop();
                else return false;
            }
            else if(e==']'){
                if(s.top()=='[') s.pop();
                else return false;
            }
        } 
        if(s.empty()) return true;
        else return false;
    }
};