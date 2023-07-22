class Solution {
public:
    int xm[8] = {1,2,2,1,-1,-2,-2,-1};
    int ym[8] = {2,1,-1,-2,-2,-1,1,2};
    int N;
    vector<vector<vector<double>>> pos{27,vector<vector<double>>(27,vector<double>(102,0))};
    
    double find_answer(int x, int y, int k){
        if(x<0 || y<0 || x>=N || y>=N) return 0;
        if(k==0) return pos[x][y][k]=1;
        if(pos[x][y][k] != 0) return pos[x][y][k];
        
        double tmp=0;
        for(int i=0; i<8; i++){
            tmp+=find_answer(x+xm[i],y+ym[i],k-1);
        }
        return pos[x][y][k] = tmp/8;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        N = n;
        find_answer(row,column,k);
        return pos[row][column][k];
    }
};