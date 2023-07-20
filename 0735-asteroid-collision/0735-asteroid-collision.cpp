class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> answer;
        deque<int> dq;
        for(auto e:asteroids){
            if(e>0) dq.push_back(e);
            else{
                if(dq.empty()) dq.push_back(e);
                else{
                    if(dq.back()<0) dq.push_back(e);
                    else{
                        bool flag = true;
                        while(!dq.empty() && dq.back() >0){
                            if(dq.back() < -e){
                                dq.pop_back();
                            }
                            else if(dq.back() == -e){
                                dq.pop_back();
                                flag = false;
                                break;
                            }
                            else{
                                flag = false;
                                break;
                            }
                        }
                        if(flag) dq.push_back(e);
                    }
                }
            }
        }
        while(!dq.empty()){
            answer.push_back(dq.front());
            dq.pop_front();
        }
        return answer;
    }
};