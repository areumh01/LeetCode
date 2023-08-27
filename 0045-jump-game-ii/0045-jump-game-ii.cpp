class Solution {
public:
    int jump(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
        int result[10002];
        memset(result,-1,sizeof(result));
        pq.push({0,0});
        result[0] = 0;

        while(!pq.empty()){
            int current = pq.top().second;
            int jumpnum = pq.top().first;
            pq.pop();
            if(result[current] < jumpnum) continue;
            for(int i=1; i<=nums[current]; i++){
                if(current+i >= nums.size()-1){
                    if(result[nums.size()-1] == -1)
                        result[nums.size()-1] = jumpnum+1;
                    else
                        result[nums.size()-1] = min(result[nums.size()-1],jumpnum+1);
                }
                else if(result[current+i]==-1 || result[current+i] > jumpnum+1){
                    result[current+i] = jumpnum+1;
                    pq.push({jumpnum+1,current+i});
                }
            }
        }
        return result[nums.size()-1];
    }
};