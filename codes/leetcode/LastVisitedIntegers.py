# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def lastVisitedIntegers(self, words: List[str]) -> List[int]:
        prev_pointer = -1
        prev_results = []
        for i, word in enumerate(words):
            if word == "prev":
                if prev_pointer == -1:
                    prev_results.append(-1)
                else:
                    prev_results.append(int(words[prev_pointer]))
                prev_pointer -= 1
                while prev_pointer >= 0 and words[prev_pointer] == "prev":
                    prev_pointer -= 1
                if prev_pointer < 0:
                    prev_pointer = -1
            else:
                prev_pointer = i
            print(prev_pointer)
        return prev_results

# ["1","2","prev","prev","prev"]
# ["1","prev","2","prev","prev"]
# ["prev","prev","prev","27"]
# ["prev","prev","68","prev","prev","53","40","23","prev"]