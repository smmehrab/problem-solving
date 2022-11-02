# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class Solution:
    def minMutation(self, start:str, end:str, bank:list[str]) -> int:

        possible_mutations = "ACGT"
        queue = deque()
        visited = []

        # BFS with level
        queue.append((start, 0))
        visited.append(start)
        while queue:
            node, level = queue.popleft()
            if node == end:
                return level
            for index in range(len(node)):
                for mutation in possible_mutations:
                    mutant = node[:index] + mutation + node[index+1:]
                    if mutant not in visited and mutant in bank:
                        queue.append((mutant, level+1))
                        visited.append(mutant)

        return -1