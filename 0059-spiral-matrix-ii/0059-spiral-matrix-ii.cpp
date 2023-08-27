class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> answer(n,vector<int>(n,0));
       int top = 0;
       int bottom = n-1;
       int left = 0;
       int right = n-1;
       int number = 1;
       while(left<=right){
           for(int i=left; i<=right; i++){
               answer[top][i] = number++;
           }
           top++;
           for(int i=top; i<=bottom; i++){
               answer[i][right] = number++;
           }
           right--;
           if(top<=bottom){
               for(int i=right; i>=left; i--){
                   answer[bottom][i] = number++;
               }
               bottom--;
           }
           if(left<=right){
               for(int i=bottom; i>=top; i--){
                   answer[i][left] = number++;
               }
               left++;
           }
       }
       return answer;
    }
};