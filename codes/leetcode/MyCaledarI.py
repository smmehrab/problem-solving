# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from bisect import bisect_right

class MyCalendar(object):

    def __init__(self):
        self.calendar = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        position = bisect_right(self.calendar, (start, end))
        if (position > 0 and self.calendar[position-1][1] > start) or (position < len(self.calendar) and self.calendar[position][0] < end):
            return False

        element = (start, end)
        index = position
        old_len = len(self.calendar)
        while index<old_len:
            self.calendar[index], element = element, self.calendar[index]
            index += 1
        self.calendar.append(element)

        return True

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)