# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def get_valid_spot(self, group_size, groups):
        for gindex, group in enumerate(groups):
            if len(group) == group_size:
                for mindex, member in enumerate(group):
                    if member == -1:
                        return gindex, mindex
        return -1, -1

    def groupThePeople(self, group_sizes: List[int]) -> List[List[int]]:
        groups = []
        for people, group_size in enumerate(group_sizes):
            gindex, mindex = self.get_valid_spot(group_size, groups)
            if gindex == -1:
                groups.append([-1]*group_size)
                gindex, mindex = len(groups)-1, 0
            groups[gindex][mindex] = people
        return groups

# Better Solution
import collections

class Solution:
    def groupThePeople(self, group_sizes: List[int]) -> List[List[int]]:
        groups = []
        group_size_to = collections.defaultdict(list)
        for people, group_size in enumerate(group_sizes):
            group_size_to[group_size].append(people)
        for group_size, peoples in group_size_to.items():
            people_count = len(peoples)
            for i in range(0, people_count, group_size):
                groups.append(peoples[i:i+group_size])
        return groups

