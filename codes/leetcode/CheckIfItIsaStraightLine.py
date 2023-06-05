# ************************************************
# username    :   smmehrab
# fullname    :   s.m.mehrabul islam
# email       :   mehrab.24csedu.001@gmail.com
# institute   :   university of dhaka, bangladesh
# session     :   2017-2018
# ************************************************

class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        (x1, y1), (x2, y2) = coordinates[:2]
        m2 = (y2-y1)/(x2-x1) if (x2-x1) else float('inf')
        for (x3, y3) in coordinates[2:]:
            m3 = (y3-y1)/(x3-x1) if (x3-x1) else float('inf')
            if m2 != m3:
                return False
        return True