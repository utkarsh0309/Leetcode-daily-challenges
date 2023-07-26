class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(n - 1 > hour || hour - n + 1 <= 0) return -1;
        int left = 1, right = max(*max_element(dist.begin(), dist.end()), (int)ceil(dist[n - 1] / (hour - n + 1)));
        while(left < right) {
            int mid = left + (right - left) / 2;
            double total_time = 0;
            for(int i = 0; i < n - 1; i++) total_time += ceil((double)dist[i] / mid);
            total_time += (double)dist[n - 1] / mid;
            if(total_time <= hour) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};