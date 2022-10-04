# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        DEBUG = False
        
        nums.sort()
        n = len(nums)

        local_sum = 0
        best_sum = -1
        diff = 999999

        for index, num in enumerate(nums):
            
            if DEBUG:
                print(str(index))
            
            left = index+1
            right = n-1
            while left<right:
                local_sum = num + nums[left] + nums[right]

                if DEBUG:
                    print(str(left) + " " + str(right) + " " + str(local_sum))
                    print("----------")

                if local_sum>target:
                    right -= 1

                elif local_sum<target:
                    left += 1
                    
                else:
                    return target

                if abs(target-local_sum)<diff:
                    diff = abs(target-local_sum)
                    best_sum = local_sum
                
        return best_sum
