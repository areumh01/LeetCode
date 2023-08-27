class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1] < b[1];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        vector<bool> merged(intervals.size(),false);
        sort(intervals.begin(), intervals.end(), comp);
        //for(auto e: intervals) cout << e[1] << " ";
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= intervals[i-1][1]){
                merged[i-1] = true;
                intervals[i][1] = max(intervals[i-1][1],intervals[i][1]);
                intervals[i][0] = min(intervals[i-1][0],intervals[i][0]);
            }
        }
        for(int i=0; i<intervals.size(); i++){
            if(!merged[i]) answer.push_back(intervals[i]);
        }
        return answer;
    }
};