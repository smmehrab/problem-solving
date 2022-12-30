# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        quotient = 0
        quotient_sign = -1 if (dividend < 0) ^ (divisor < 0) else 1
        dividend = abs(dividend)
        divisor = abs(divisor)
        # algorithm
        while dividend >= divisor:
            n = 0
            # find maximum 
            # divisor * (2**n) <= dividend
            while dividend-(divisor<<1<<n) >= 0:
                n += 1
            quotient += (1<<n)
            dividend -= (divisor<<n)
        # quotient processing
        quotient *= quotient_sign
        left_fence = (-1)*(2**31)
        right_fence = (2**31)-1
        quotient = max(left_fence, quotient)
        quotient = min(quotient, right_fence)
        return quotient