# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class SummaryRanges:

    def __init__(self):
        self.parent = {}
        self.intervals = {}

    def addNum(self, val: int) -> None:
        if self._exists(val):
            return
        self._add(val)
        self._union(val, val-1)
        self._union(val, val+1)

    def getIntervals(self) -> List[List[int]]:
        return sorted(self.intervals.values())

    def _exists(self, x): 
        return x in self.parent

    def _add(self, x):
        self.parent[x] = x
        self.intervals[x] = [x,x]

    def _find(self, x):
        if not self._exists(x): 
            return None
        elif self.parent[x] != x:
            self.parent[x] = self._find(self.parent[x])
        return self.parent[x]

    def _union(self, x, y):
        x_root = self._find(x)
        y_root = self._find(y)
        if x_root is None or y_root is None:
            return
        self.parent[x_root] = y_root

        x_interval = self.intervals[x_root]
        y_interval = self.intervals[y_root]
        del self.intervals[x_root]

        interval_left = min(x_interval[0], y_interval[0])
        interval_right = max(x_interval[1], y_interval[1])
        self.intervals[y_root] = [interval_left, interval_right]

# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()