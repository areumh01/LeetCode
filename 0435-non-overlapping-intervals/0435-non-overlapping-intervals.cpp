class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        //if(a[1] != b[1]) 
        return a[1]<b[1];
        //else return a[0] > b[0];
    };

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int answer=0;
        sort(intervals.begin(), intervals.end(), comp);

        int last = 0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= intervals[last][1]){
                last = i;
            }
            else answer++;
        }
        return answer;
    }
};