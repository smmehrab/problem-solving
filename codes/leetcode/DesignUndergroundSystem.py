# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class UndergroundSystem:
    def __init__(self):
        self.history = {}
        self.current = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.current[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        start_station, start_time = self.current.pop(id)
        trip = (start_station, stationName)
        time = t - start_time
        if trip in self.history:
            total_time, count = self.history[trip]
            self.history[trip] = (total_time + time, count + 1)
        else:
            self.history[trip] = (time, 1)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        trip = (startStation, endStation)
        total_time, count = self.history[trip]
        return total_time / count

# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)