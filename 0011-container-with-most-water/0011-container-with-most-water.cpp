class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int left = start;
        int right = end;
        int answer = 0;
        
        while(start<=end){
            answer = max(answer,(right-left)*min(height[right],height[left]));
            if(height[left]<=height[right])
                while(start<=end && height[left]>=height[start]) start++;
            else
                while(start<=end && height[right]>=height[end]) end--;
            left = start;
            right = end;
        }
        
        return answer;
    }
};