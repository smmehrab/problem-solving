# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class EulerTotientFunction:

    """
        Euler's Product Formula
        -----------------------------------------------------
        phi(n)  =   n*(1-(1/p1))*(1-(1/p2))* ... * (1-(1/pk))
        -----------------------------------------------------
        -   number of numbers from 1 to n-1
            1 <= m <= n
        -   which are coprime with n
            gcd(m, n) == 1
        -----------------------------------------------------
    """

    def __init__(self, n=None) -> None:
        if n is not None:
            self.phi = [0]*(n+2)
            self.calculate_all(n)
        else:
            self.phi = []

    # O(n*n)
    def calculate_all(self, n) -> None:
        # initialize
        for i in range(1, n+1):
            self.phi[i] = i

        # algorithm
        for p in range(2, n+1):
            # prime
            if (self.phi[p] == p):
                self.phi[p] = p-1
    
                # update multiples of p
                for i in range(2*p, n+1, p):
                    # multiply with (1 - 1/p)
                    self.phi[i] = (self.phi[i]//p) * (p-1)

    # O(√n log n)
    def calculate(self, n) -> int:
        count = n
        p = 2
        while (p*p) <= n:
            if (n%p) == 0:
                while (n%p) == 0:
                    n = int(n/p)
                count -= int(count/p)
            p += 1
        if n>1:
            count -= int(count/n)
        return count

    # O(1)
    def get(self, i) -> int:
        if len(self.phi)>0:
            return self.phi[i]
