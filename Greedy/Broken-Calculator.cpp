class Solution {
public:
    int brokenCalc(int x, int y) {
        int count = 0;
        while (y != x) {
            if (x >= y) 
                return (x - y) + count;
            y = (y % 2 == 0) ? y / 2 : y + 1;
            count++;
        }
        return count;
    }
};

// reattempt: didnt solve on my, the intuition did not come to me at all even for the second time
// What the trick was that , we start from the target and then try decrease by /= 2 if it is even and add + 1 if odd, to reach the startValue,
// But there will be a case in which target becomes less than or equal to startValue, in that case all we can do is add +1 . that can be easily done
// by just taking the diff of start and target.
class Solution {
public:
    int brokenCalc(int x, int y) {
        long long count = 0;
        while (y != x) {
            if (x >= y){
                return (x - y) + count;
            }
        
            if (y % 2 == 0) {
                y /= 2;
            } else {
                y++;
            }
            count ++;
        }

        return count;
    }
};
