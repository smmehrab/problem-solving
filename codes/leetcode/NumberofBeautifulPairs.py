# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def __init__(self):
        self.gcd_cache = {}

    def gcd(self, a, b):
        if (a, b) in self.gcd_cache:
            return self.gcd_cache[(a, b)]
        
        while b != 0:
            a, b = b, a % b

        self.gcd_cache[(a, b)] = a
        return a

    def is_coprime(self, x, y):
        return self.gcd(x, y) == 1

    def countBeautifulPairs(self, nums: List[int]) -> int:
        count = 0
        n = len(nums)
        for i in range(n - 1):
            nums_str = str(nums[i])
            first = int(nums_str[0])
            for j in range(i + 1, n):
                last = nums[j]%10
                if (first, last) in self.gcd_cache or (last, first) in self.gcd_cache:
                    continue
                if self.is_coprime(first, last):
                    # print(str(first) + " " + str(last))
                    count += 1
        return count
