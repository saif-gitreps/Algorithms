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

class UndergroundSystem {
// Would say a much better approach in terms of time complexity. All ~ O(1).
public:
    map<pair<string, string>, pair<double, int>> avg_time;
    unordered_map<int, pair<string, int>> mp;
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int time = abs(mp[id].second - t);
        double avg = 0.0;
        if(avg_time.find({mp[id].first, stationName}) != avg_time.end()){
            int freq = avg_time[{mp[id].first, stationName}].second;
            avg = (avg_time[{mp[id].first, stationName}].first + time);
            avg_time[{mp[id].first, stationName}] = {avg, freq + 1};
        }
        else{
            avg_time[{mp[id].first, stationName}] = {time, 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return avg_time[{startStation, endStation}].first / 
               avg_time[{startStation, endStation}].second;
    }
};

