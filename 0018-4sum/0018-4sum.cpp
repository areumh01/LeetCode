class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        int n = nums.size();
        
        if(n<4) return {};
        
        vector<int> tmp(4);
        for(int i=0; i<n-3; i++){
            tmp[0] = nums[i];
            for(int j=i+1; j<n-2; j++){
                tmp[1] = nums[j];
                long long newTarget = (long long)target-(long long)tmp[0]-(long long)tmp[1];
                int start = j+1;
                int end = n-1;
                while(start<end){
                    if((long long)nums[start]+(long long)nums[end] < newTarget) start++;
                    else if((long long)nums[start]+(long long)nums[end] > newTarget) end--;
                    else{
                        tmp[2] = nums[start++];
                        tmp[3] = nums[end--];
                        answer.push_back(tmp);
                    }
                }
            }
        }
        sort(answer.begin(),answer.end());
        answer.erase(unique(answer.begin(),answer.end()), answer.end());
        return answer;
    }
};