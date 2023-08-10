class Solution {
public:
    vector<pair<int,int>> nums;
    bool answer = false;
    
    bool isValid(vector<vector<char>>& board, int r, int c){
        for(int i=0; i<9; i++) if(c!=i&&board[r][i]==board[r][c]) return false;
        for(int i=0; i<9; i++) if(r!=i&&board[i][c]==board[r][c]) return false;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(c!=(c-(c%3)+j)&&r!=(r-(r%3)+i)&&board[r-(r%3)+i][c-(c%3)+j]==board[r][c]) return false;
            }
        }
        return true;
    }

    void backTracking(vector<vector<char>>& board,int index){
        if(index==nums.size()) {
            answer = true;
            return;
        }
        int r = nums[index].first;
        int c = nums[index].second;
        if(isValid(board,r,c)) backTracking(board,index+1);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] != '.') nums.push_back({i,j});
            }
        }
        backTracking(board,0);
        return answer;
    }
};