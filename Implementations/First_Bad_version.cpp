// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// first attempt , worked till 10 cases.
class Solution {
public:
    int mn = INT_MAX;
    int firstBadVersion(int n) {
         if(n==0){
           return mn;
        }
        else{
            if(isBadVersion(n)){
                mn = min(mn,n);
            }
            return firstBadVersion(n-1);
        }   
    }
};
class Solution {
    //better version.
public:
    int mn = INT_MAX;
    int firstBadVersion(int n) {
        int low = 0,high = n;
        int mid,res;
        while(low<=high){
            mid = high+(low-high)/2;
            if(isBadVersion(mid)){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};
