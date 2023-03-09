# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def rectangleArea(self, rectangles: list[list[int]]) -> int:
        # Populate events
        OPEN, CLOSE = 0, 1
        events = []
        for xBL, yBL, xTR, yTR in rectangles:
            events.append((yBL, OPEN, xBL, xTR))
            events.append((yTR, CLOSE, xBL, xTR))
        events.sort()

        def query():
            ans = 0
            cur = -1
            for x1, x2 in active:
                cur = max(cur, x1)
                ans += max(0, x2 - cur)
                cur = max(cur, x2)
            return ans

        active = []
        cur_y = events[0][0]
        ans = 0
        for y, typ, x1, x2 in events:
            # For all vertical ground covered, update answer
            ans += query() * (y - cur_y)

            # Update active intervals
            if typ is OPEN:
                active.append((x1, x2))
                active.sort()
            else:    
                active.remove((x1, x2))

            cur_y = y

        return ans % (10**9 + 7)