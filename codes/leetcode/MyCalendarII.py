# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class MyCalendarTwo(object):

    def __init__(self):
        self.events = []
        self.overlaps = []
    
    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        for overlap_start, overlap_end in self.overlaps:
            if start < overlap_end and end > overlap_start:
                return False
        for event_start, event_end in self.events:
            if start < event_end and end > event_start:
                overlap = (max(start, event_start), min(end, event_end))
                self.overlaps.append(overlap)
        self.events.append((start, end))
        return True

# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)