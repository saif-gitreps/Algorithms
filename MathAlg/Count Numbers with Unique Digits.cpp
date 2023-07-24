class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
            return 1;
        }
        int ans=10;int nine=9;int count = 9;
        for(int i = 0; i < n - 1; i++) {
            nine *= count;
            ans += nine;
            count--;
        }
        return ans;
        
    }
};
