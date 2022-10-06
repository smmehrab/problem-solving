# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class TimeMap(object):

    def __init__(self):
        self.time_map = dict()

    def set(self, key, value, timestamp):
        """
        :type key: str
        :type value: str
        :type timestamp: int
        :rtype: None
        """
        if key not in self.time_map:
            self.time_map[key] = []
        self.time_map[key].append((value, timestamp))

    def get(self, key, timestamp):
        """
        :type key: str
        :type timestamp: int
        :rtype: str
        """
        if key not in self.time_map:
            return ""

        value, time = self.time_map[key][0]
        if timestamp < time:
            return ""
        
        # binary search (timestamp)
        left = 0
        right = len(self.time_map[key])
        while left < right:
            mid = (left + right) // 2
            value, time = self.time_map[key][mid]
            if time <= timestamp:
                left = mid + 1
            else:
                right = mid

        return "" if right == 0 else self.time_map[key][right-1][0]

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
