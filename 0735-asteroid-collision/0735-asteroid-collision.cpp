class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> answer;
        stack<int> s;
        for(auto e:asteroids){
            if(e>0) s.push(e);
            else{
                if(s.empty() || s.top() < 0) s.push(e);
                else{
                    while(!s.empty() && s.top()>0 && s.top()<-e){
                        s.pop();
                    }
                    //s가 비거나 s.top이 음수가 되거나 e의 절댓값보다 커서 탈출
                    if(!s.empty() && s.top()==-e) s.pop();
                    else if(s.empty() || s.top()<0) s.push(e);
                }
            }
        }
        answer.resize(s.size());
        int size = s.size();
        int i=1;
        while(!s.empty()){
            answer[size-i] = s.top();
            s.pop();
            i++;
        }
        return answer;
    }
};