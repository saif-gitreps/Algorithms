class Solution {
// first_attempt , passed till 2/3 of the test cases , need to figure out the -1 edge cases condition.
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int right  = 1, left = 1 ,mid;
        for(int i = 0 ; i < dist.size(); i++){
            right = max(right, dist[i]);
        }
        while(left < right){
            mid = left + (right-left)/2;
            double total_hour = 0;
            for(int i = 0 ; i < dist.size()-1; i++){
                total_hour += ceil((double)dist[i] / mid);
            }
            total_hour += ( dist[dist.size()-1] / mid );
            if(total_hour == hour){
                return mid;
            }
            if (total_hour > hour) {
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return right;
    }
};


class Solution {
// similar code , i think the return statement had issues.
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int right  = 10000000, left = 1;
        long long int mid;
        if (hour < dist.size() - 1) {
            return -1;
        }
        while(left <= right){
            mid = left + (right-left)/2;
            double total_hour = 0;
            for(int i = 0 ; i < dist.size(); i++){
                total_hour = ceil(total_hour);
                total_hour += ((double)dist[i] / mid);
            }
            if (total_hour > hour) {
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return (left > 10000000) ? -1 : left;
    }
};
