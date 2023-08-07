class Solution {
public:
    bool bs(vector<vector<int>>& matrix, int m, int target){
        int start =0;
        int end = matrix[m].size()-1;
        
        while(start<=end){
            int mid = (start+end)/2;
            if(matrix[m][mid] < target) start=mid+1;
            else if(matrix[m][mid] > target) end = mid-1;
            else return true;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[matrix.size()-1][0] <= target) return bs(matrix, matrix.size()-1,target);
        
        int start=0;
        int end = matrix.size()-1;
        while(start<end-1){
            int mid = (start+end)/2;
            if(matrix[mid][0] > target) end = mid;
            else start = mid;
        }
        return bs(matrix, start, target);
    }
};