class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        if(s.size()==0) return 0;
        
        int start=0;
        int end=0;
        int answer=0;
        
        while(end<=s.size()-1){
            if(m[s[end]]==0) m[s[end]]++;
            else{
                m[s[end]]++;
                //cout << start << " " << end << '\n';
                answer = max(answer,end-start);
                while(start<end && m[s[end]]>1) m[s[start++]]--;
            }
            end++;
        }
        answer = max(answer,end-start);
        return answer;
    }
};