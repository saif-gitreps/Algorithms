class Solution {
// The first hint helped me to think through the solution.
public:
    int minMoves(int target, int maxDoubles) {
        if(!maxDoubles){
            return --target;
        }

        int count = 0;
        while(target > 1) {
            if(target % 2 == 0 && maxDoubles){
                target /= 2;
                maxDoubles--;
            }
            else{
                target--;
            }
            count ++;
        }
        return count;
    }
};
