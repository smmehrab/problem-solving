# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def get_code(self, c1, c2, c3):
        temp = [c1, c2, c3]
        temp.sort()
        code = 1
        for i in range(3):
            code *= self.primes[i] ** temp[i]
        return code

    def distributeCandies(self, n: int, limit: int) -> int:
        self.primes = [2, 3, 5]
        ways = 0
        included = []
        for c1 in range(min(n, limit) + 1):
            remaining = n - c1
            for c2 in range(min(remaining, limit) + 1):
                remaining = n - c1 - c2
                c3 = min(remaining, limit)
                total = c1 + c2 + c3
                if total == n:
                    code = self.get_code(c1, c2, c3)
                    if code in included:
                        continue
                    included.append(code)
                    if c1 == c2 == c3:
                        ways += 1
                    elif c1 == c2 or c1 == c3 or c2 == c3:
                        ways += 3
                    else:
                        ways += 6
        return ways