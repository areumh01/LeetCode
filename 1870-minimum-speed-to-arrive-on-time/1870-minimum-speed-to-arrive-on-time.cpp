class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour <= dist.size()-1) return -1;
        
        int start=1;
        int end = 10000000;
        int mid=0;
        while(start<end){
            mid = (start+end)/2;
            double sum=0;
            for(int i=0; i<dist.size()-1; i++) sum+=ceil(dist[i]/(double)mid);
            sum += dist.back()/(double)mid;
            if(sum > hour) start=mid+1;
            else end = mid;
        }
        return end;
    }
};