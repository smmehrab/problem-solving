class RabinKarp:

    def __init__(self, base, modulo):
        self.base = base
        self.modulo = modulo
        pass

    def find(self, pattern, text):
        indices = []
        n = len(text)
        m = len(pattern)

        # calculate msb factor [base ^ (m-1)]
        msbFactor = 1
        for i in range(m-1):
            msbFactor = (msbFactor*self.base) % self.modulo

        # calculate initial [hp, ht]
        hp = 0
        ht = 0
        for i in range(m):
            hp = (self.base*hp + ord(pattern[i])) % self.modulo
            ht = (self.base*ht + ord(text[i])) % self.modulo

        # sliding window | rolling hash
        for i in range(n-m+1):
            if hp == ht:
                for j in range(m):
                    if text[i+j] != pattern[j]:
                        break
                    if j==m-1:
                        indices.append(i)
                        print("Index: " + str(i) + " [Pattern Found]")
                        break

            if i < n-m:
                ht = (self.base*(ht-(ord(text[i])*msbFactor)) + ord(text[i+m])) % self.modulo
                if ht < 0:
                    ht += self.modulo

        return indices