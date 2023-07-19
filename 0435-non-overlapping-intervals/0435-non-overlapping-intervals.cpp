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

        int last = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= last){
                last = intervals[i][1];
            }
            else answer++;
        }
        return answer;
    }
};