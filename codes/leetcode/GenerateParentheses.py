# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def generate(self, oi, ci, combination):
        
        if oi>self.n or ci>self.n:
            return

        elif oi == self.n and ci == self.n:
            self.combinations.append("".join(combination))

        elif oi>ci:
            # choice 1
            combination.append("(")
            self.generate(oi+1, ci, combination)
            combination.pop()
            # choice 2
            combination.append(")")
            self.generate(oi, ci+1, combination)
            combination.pop()

        else:
            # choice 1
            combination.append("(")
            self.generate(oi+1, ci, combination)
            combination.pop()

    def generateParenthesis(self, n: int) -> list[str]:
        self.n = n
        self.combinations = []
        self.generate(0, 0, [])
        return self.combinations
