class Solution1 {
public:
    // very slow solution.
    int addDigits(int num) {
        long long sum = 0;
        while(num>=10){
            sum =0;
            while(num>0){
                sum += num%10;
                num/=10;
            }
            num = sum;
        }
        return num;
    }
};

// explanation for this algorthm in below:
/*
    So for any number that isn't 0 and isn't divisible by 9, the root will always n % 9 for a given number n. 
    (AKA the difference between given number n and the nearest number that is divisible by 9, 
    since numbers divisible by 9 always have a digital root of 9).
    For examples: 100 % 9 = 1 (one greater than 99, which is divisible by 9).
    101 % 9 = 2
    102 % 9 = 3 and so on.
*/

int addDigits(int num) {
        if(num<=9) return num;
        else if(num%9==0) return 9;
        else return num%9;
    }
