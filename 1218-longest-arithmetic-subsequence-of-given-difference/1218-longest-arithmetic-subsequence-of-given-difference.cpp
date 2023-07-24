class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int visited[40002]={0,};
        int longest[40002]={0,};
        int answer=0;
        
        for(int i=arr.size()-1; i>=0; i--){
            int current = arr[i]+20000;
            if(!visited[current+difference]) longest[current]=1;
            else longest[current] = longest[current+difference]+1;
            visited[current]=1;
            answer = max(answer,longest[current]);
            //cout << arr[i] << " " << longest[current] << " " << answer << '\n';
        }
        
        return answer;
    }
};