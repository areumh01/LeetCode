class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left=0;
        int right = k-1;
        priority_queue<pair<int,int>> pq;
        vector<int> answer;

        for(int i=0; i<k; i++){
            pq.push({nums[i],i});
        }
        answer.push_back(pq.top().first);

        while(right<nums.size()-1){
            right++;
            left++;
            pq.push({nums[right],right});
            while(pq.top().second > right || pq.top().second<left){
                pq.pop();
            }
            answer.push_back(pq.top().first);
        }
        return answer;
    }
};