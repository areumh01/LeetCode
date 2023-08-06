class Solution {
public:
    vector<int> tmp;
    
    void next_perm(int index){
        cout << index << '\n';
        int number;
        for(int i=tmp.size()-1; i>index; i--){
            if(tmp[index] < tmp[i]){
                number=tmp[i];
                tmp[i] = tmp[index];
                tmp[index] = number;
                break;
            }
        }
        sort(tmp.begin()+index+1, tmp.end());
    }
    
    void nextPermutation(vector<int>& nums) {
        tmp = nums;
        bool flag = false;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                next_perm(i);
                flag = true;
                break;
            }
        }
        if(!flag) sort(tmp.begin(),tmp.end());
        nums = tmp;
    }
};