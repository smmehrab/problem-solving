# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def computeArea(self, ax1, ay1, ax2, ay2, bx1, by1, bx2, by2):
        """
        :type ax1: int
        :type ay1: int
        :type ax2: int
        :type ay2: int
        :type bx1: int
        :type by1: int
        :type bx2: int
        :type by2: int
        :rtype: int
        """
        
        if ax1 > by1:
            ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 = bx1, by1, bx2, by2, ax1, ay1, ax2, ay2
                
        area = 0
        area1 = ((ax2-ax1)*(ay2-ay1))
        area2 = ((bx2-bx1)*(by2-by1))
        
        overlapped_width = max(min(ax2, bx2)-max(ax1, bx1), 0)
        overlapped_height = max(min(ay2, by2)-max(ay1, by1), 0)
        overlapped = overlapped_width * overlapped_height

        area = area1 + area2 - overlapped
        return area
