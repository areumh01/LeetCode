class Solution {
public:
    int romanToInt(string s) {
        int alpha[28] = {0};
        vector<int> converted;
        int answer=0;
        alpha['I'-'A'] = 1;
        alpha['V'-'A'] = 5;
        alpha['X'-'A'] = 10;
        alpha['L'-'A'] = 50;
        alpha['C'-'A'] = 100;
        alpha['D'-'A'] = 500;
        alpha['M'-'A'] = 1000;
        
        for(char c:s){
            converted.push_back(alpha[c-'A']);
        }
        
        int latest=0;
        for(int i=converted.size()-1; i>=0; i--){
            if(converted[i]>=latest) answer+=converted[i];
            else answer-=converted[i];
            latest=converted[i];
        }
        
        return answer;
    }
};