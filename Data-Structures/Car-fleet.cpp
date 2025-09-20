
class Solution {
/*
heres how it works, 
how do i know if two cars are in the same fleet, we first sort it based on the position
then from backwards, as in from reverse or from the car that has less distance to the target.
then one by one we check the speed, if the time to reach of the car before the ith car is less, it means,
Hypothetically there will be a time when it shall catch up, and after catching up, it will reduce its speed
to the one in front, or the slowest, thus forming a fleet,
If the time to reach the target is greater for the previous previous, then we know it will never catch up.
so therefore, the seoncd fleet will be formed.
*/
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> mp;
        
        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            mp[-position[i]] = time;
        }

        int ans = 0;
        double current = 0;

        for (auto it: mp) {
            if (it.second > current) {
                ans++;
                current = it.second;
            }
        }

        return ans;
    }
};
