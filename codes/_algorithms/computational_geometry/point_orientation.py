# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def _orientation(p1, p2, p3):
    # p3's orientation from (p1---p2)
    # 0 --> Colinear
    # 1 --> Clockwise
    # 2 --> Counterclockwise
    direction = ((p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y))
    if direction == 0:
        return 0
    elif direction > 0:
        return 1
    else:
        return 2
