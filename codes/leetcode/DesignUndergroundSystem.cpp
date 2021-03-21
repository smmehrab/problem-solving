class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> log;
    unordered_map<string, pair<int, int>> history;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string station, int time) {
        log[id] = {station, time};
    }
    
    void checkOut(int id, string station, int time) {
        pair<string, int> entry = log[id];
        
        string startStation = entry.first;
        int startTime = entry.second;
        
        string trip = startStation + station;
        
        auto &data = history[trip];        
        auto &tripCount = data.first;
        auto &totalTime = data.second;
        
        tripCount++;
        totalTime += time-startTime;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string trip = startStation + endStation;
        
        pair<int, int> data = history[trip];
        int tripCount = data.first;
        int totalTime = data.second
            ;
        return totalTime/(1.00*tripCount);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */