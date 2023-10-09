# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def binary_search(self, nums, target, mode):
        left, right = 0, len(nums) - 1
        index = -1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                index = mid
                # lowerbound
                if mode == 0:
                    right = mid - 1
                # upperbound
                else:
                    left = mid + 1
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return index

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        starting_position = self.binary_search(nums, target, 0)
        ending_position = self.binary_search(nums, target, 1)
        return [starting_position, ending_position]