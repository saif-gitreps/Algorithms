class Solution {
public:
    long long minimumTime(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        long long left = 0;
        long long right = 1LL*target*a[a.size()-1];
        long long min_time = 1LL*target*a[a.size()-1];
        long long mid;
        while(left<right){
            mid = left + (right-left)/2;
            long long total_trip = 0;
            for(int i=0;i<a.size();i++){
                total_trip += (mid/a[i]);
            }            
            if(total_trip>=target){
                right = mid;
                min_time = min(min_time,mid);
            }
            else{
                left = mid+1;
            }
        }
        return min_time;

    }
};
