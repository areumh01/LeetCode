class Solution {
public:
    string answer="";

    string reorganizeString(string s) {
        map<char,int> m;
        priority_queue<pair<int,char>> pq;
        
        for(auto e : s){
            m[e]++;
        }

        map<char,int>::iterator it;
        for(it=m.begin(); it!=m.end(); it++){
            pq.push({it->second,it->first});
        }

        while(pq.size()>=2){
            pair<int, char> p1 = pq.top();pq.pop();
            pair<int, char> p2 = pq.top();pq.pop();

            answer+=p1.second;
            answer+=p2.second;
            if(--p1.first>0) pq.push({p1.first,p1.second});
            if(--p2.first>0) pq.push({p2.first,p2.second});
        }
        while(!pq.empty()){
            pair<int, char> p1 = pq.top();pq.pop();
            if(p1.first>1) return "";
            answer+=p1.second;
        }
        return answer;
    }
};