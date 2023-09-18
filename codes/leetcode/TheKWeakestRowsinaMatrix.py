# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
      n = len(mat[0])
      matmap = []
      for i, row in enumerate(mat):
        one_count = 0
        while one_count<n and row[one_count] == 1:
          one_count += 1
        matmap.append((i, one_count))

      matmap.sort(key=lambda x: x[1])
      
      result = []
      for i in range(k):
        result.append(matmap[i][0])
      return result

