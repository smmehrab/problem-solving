# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Point:
    def __init__(self, x=None, y=None) -> None:
        self.x = x
        self.y = y

class Segment:
    def __init__(self, start:Point=None, end:Point=None) -> None:
        self.start = start
        self.end = end

class BentleyOttmann:
    