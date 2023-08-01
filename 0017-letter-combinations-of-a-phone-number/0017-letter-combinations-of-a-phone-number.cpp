class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> nums = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> answer;
        vector<char> tmp(digits.size());
        int i=0; //for digits
        int k=0; //for "abc", "def" etc...
        stack<int> s;
        
        while(i>=0){
            int index = digits[i]-'0';
            string dials = nums[index-1]; // "abc", "def" etc..
            tmp[i] = dials[k++];
            if(k>dials.size()){
                i--;
                if(s.empty()) break;
                k=s.top();
                s.pop();
            }
            else if(i==digits.size()-1){
                string sub="";
                for(auto e:tmp) sub+=e;
                answer.push_back(sub);
            }
            else{
                i++;
                s.push(k);
                k=0;
            }
        }
        
        return answer;
    }
};