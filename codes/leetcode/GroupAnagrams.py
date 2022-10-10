# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    
    def __init__(self):
        self.primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101]

    def h(self, s):
        hash_value = 1
        base_value = ord('a')
        for c in s:
            prime_index = ord(c)-base_value
            hash_value *= self.primes[prime_index]
        return hash_value
            
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        
        hToIndex = dict()
        anagrams = []
        for s in strs:
            hs = self.h(s)
            if hs in hToIndex:
                index = hToIndex.get(hs)
            else:
                anagrams.append([])
                index = len(anagrams)-1
                hToIndex[hs] = index
            anagrams[index].append(s)
        
        return anagrams
