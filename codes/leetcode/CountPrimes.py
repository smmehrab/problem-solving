# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def get_primes(self, n):
        isPrime = [True]*(n+1)
        p = 2
        while (p*p)<=n:
            if isPrime[p]:
                for i in range((p*p), (n+1), p):
                    isPrime[i] = False
            p += 1

        primes = []
        for p in range(2, n+1):
            if isPrime[p]:
                primes.append(p)
        return len(primes)

    def countPrimes(self, n: int) -> int:
        return self.get_primes(n-1)
