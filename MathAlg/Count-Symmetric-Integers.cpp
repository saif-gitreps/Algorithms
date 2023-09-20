class Solution {
// First attempt in the contest , several 100/2000 failed.
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high ; i++){
            string num = to_string(i);
            int sum1 = 0; int sum2 = 0;
            for(int j = 0; j < num.size()/2; j ++){
                sum1 += num[j] - '0';
                sum2 += num[num.size()-j-1] - '0';
            }
            if(sum1 == sum2 && sum1 != 0 && sum2 != 0){
                count++;
            }
        }
        return count;
    }
};
