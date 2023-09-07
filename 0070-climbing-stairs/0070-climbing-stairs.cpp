class Solution {
public:
    int climbStairs(int n) {
        int all[50];
        all[0] = 0;
        all[1] = 1;
        all[2] = 2;
        if(n<3){
            return all[n];
        }
        for(int i=3; i<=n; i++){
            all[i] = all[i-1]+all[i-2];
        }
        return all[n];
    }
};