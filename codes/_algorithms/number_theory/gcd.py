# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class GCD:

    def __init__(self):
        pass

    def euclid(self, a, b):
        while(b):
            a, b = b, a % b
        return abs(a)

    def extended_euclid(self, a, b):
        if a == 0 :
            return b,0,1

        gcd,x1,y1 = self.extended_euclid(b%a, a)
        x = y1 - (b//a) * x1
        y = x1

        return gcd,x,y