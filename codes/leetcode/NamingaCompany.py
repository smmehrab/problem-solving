# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import defaultdict

class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        hash_set = collections.defaultdict(set)
        for idea in ideas:
            key, suffix = idea[0], idea[1:]
            hash_set[key].add(suffix)

        distinct_names_count = 0
        for key1 in hash_set:
            for key2 in hash_set:
                if key1 == key2:
                    continue
                duplicate = 0
                for suffix in hash_set[key1]:
                    if suffix in hash_set[key2]:
                        duplicate += 1
                distinct1 = len(hash_set[key1]) - duplicate
                distinct2 = len(hash_set[key2]) - duplicate
                distinct_names_count += (distinct1*distinct2)

        return distinct_names_count

