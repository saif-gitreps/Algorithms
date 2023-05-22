class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 1;
        int big = max(a,b);
        int sma = min(a,b);
        for(int i=2;i<=big;i++){
            if(big%i==0 && sma%i==0){
                count++;
            }
        }
        return count;
    }
};
