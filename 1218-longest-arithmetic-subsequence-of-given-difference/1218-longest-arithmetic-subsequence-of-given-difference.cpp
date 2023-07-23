class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        set<int> s;
        map<int,int> m;
        int answer=0;
        
        for(int i=arr.size()-1; i>=0; i--){
            if(s.find(arr[i]+difference)==s.end()) m[arr[i]]=1;
            else m[arr[i]]=m[arr[i]+difference]+1;
            s.insert(arr[i]);
            answer=max(answer,m[arr[i]]);
        }
        
        return answer;
    }
};