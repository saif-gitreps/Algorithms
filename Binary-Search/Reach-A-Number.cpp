class Solution {
// sol 1.
public:
    int reachNumber(int t) {
        t = abs(t);
        long long sum = 0;
        int steps = 0;
        while (sum < t){
            steps++;
            sum += steps;
        }
        while((sum - t) % 2 != 0){
            steps++;
            sum += steps;
        }
        return steps;
    }
};
