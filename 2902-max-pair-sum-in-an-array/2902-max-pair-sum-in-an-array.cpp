class Solution {
public:
    int maxSum(vector<int>& nums) {
        //각 숫자의 maximum digit꺼내고 && index까지 따로 저장
        vector<vector<int>> v(10);
        int answer=0;
        
        for(int i=0; i<nums.size(); i++){
            string s = to_string(nums[i]);
            sort(s.begin(),s.end(),greater());
            v[s[0]-'0'].push_back(nums[i]);
        }
        
        for(int i=0; i<10; i++){
            if(v[i].size()<2) continue;
            sort(v[i].begin(),v[i].end(),greater());
            answer = max(answer,v[i][0]+v[i][1]);
        }
        if(answer==0) return -1;
        return answer;
    }
};