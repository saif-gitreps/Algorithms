class UndergroundSystem {
// Naive attempt. Worked tho.
public:
    map<pair<string, string>, vector<int>> avg_time;
    map<int, pair<string, int>> mp;
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string loc1 = mp[id].first;
        int time = abs(mp[id].second - t);
        avg_time[{loc1, stationName}].push_back(time);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avg = 0.0;
        for(auto time : avg_time[{startStation, endStation}]){
            avg += time;
        }
        return avg / avg_time[{startStation, endStation}].size();
    }
};
