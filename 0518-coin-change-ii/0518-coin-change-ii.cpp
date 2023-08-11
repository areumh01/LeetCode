class Solution {
public:

    int change(int amount, vector<int>& coins) {
        vector<int> answer(amount+2);
        sort(coins.begin(),coins.end());
        answer[0]=1;
        
        for(int j=0; j<coins.size(); j++){
            for(int i=1; i<=amount; i++){
                if(i>=coins[j]) answer[i] += answer[i-coins[j]];
            }
        }
        return answer[amount];
    }
};