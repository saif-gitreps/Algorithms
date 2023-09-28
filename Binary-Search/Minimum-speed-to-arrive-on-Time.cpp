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
