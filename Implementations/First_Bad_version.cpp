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
