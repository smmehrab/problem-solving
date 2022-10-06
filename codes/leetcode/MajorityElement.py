# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class MooreMajorityVoting():

    def __init__(self, votes):
        self.votes = votes

    def find_majority(self):
        candidate, vote_count = None,0

        # finding candidate (if there's a majority)
        for vote in self.votes:
            if vote_count == 0:
                candidate = vote
                vote_count = 1
            else:
                vote_count += 1 if vote == candidate else (-1)

        # validating if the candidate is a majority
        vote_count = 0
        for vote in self.votes:
            if vote == candidate:
                vote_count += 1
        candidate = candidate if vote_count > (len(self.votes)//2) else -1

        return candidate

    def find_two_majority(self):
        candidate1, vote_count1 = None,0
        candidate2, vote_count2 = None,0

        # finding candidates (if there's two majority)
        for vote in self.votes:
            if vote_count1 == 0:
                candidate1 = vote
                vote_count1 = 1
            elif vote_count2 == 0:
                candidate2 = vote
                vote_count2 = 1
            elif vote == candidate1:
                vote_count1 += 1
            elif vote == candidate2:
                vote_count2 += 1
            else:
                vote_count1 -= 1
                vote_count2 -= 1

        # validating if the candidates is a majority
        vote_count1, vote_count2 = 0
        for vote in self.votes:
            if vote == candidate1:
                vote_count1 += 1
            elif vote == candidate2:
                vote_count2 += 1
        candidate1 = candidate1 if vote_count1 > (len(self.votes)//2) else -1
        candidate2 = candidate2 if vote_count2 > (len(self.votes)//2) else -1

        return candidate1, candidate2

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return MooreMajorityVoting(nums).find_majority()
