bool comparator(pair<int, int> a, pair<int,int> b) {
    return a.first < b.first;
}
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> mp;
        for (int i = 0; i < position.size(); i++) {
            double time = (target - position[i]) / speed[i];
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
