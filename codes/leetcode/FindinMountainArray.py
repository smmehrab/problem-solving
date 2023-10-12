# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:

        n = mountain_arr.length()
        cache = {}

        # find peak index
        left = 1
        right = n - 2
        while left != right:
            mid = (left + right) >> 1

            x = cache[mid] if mid in cache else mountain_arr.get(mid)
            cache[mid] = x if mid not in cache else cache[mid]
            y = cache[mid+1] if mid+1 in cache else mountain_arr.get(mid+1)
            cache[mid+1] = y if mid+1 not in cache else cache[mid+1]

            if x < y:
                if x == target:
                    return mid
                if y == target:
                    return mid + 1
                left = mid + 1
            else:
                right = mid
        
        peak_index = left

        # search uphill
        left = 0
        right = peak_index
        while left <= right:
            mid = (left + right) >> 1

            x = cache[mid] if mid in cache else mountain_arr.get(mid)
            cache[mid] = x if mid not in cache else cache[mid]

            if x == target:
                return mid
            elif x < target:
                left = mid + 1
            else:
                right = mid - 1

        # search downhill
        left = peak_index + 1
        right = n - 1
        while left <= right:
            mid = (left + right) >> 1

            x = cache[mid] if mid in cache else mountain_arr.get(mid)
            cache[mid] = x if mid not in cache else cache[mid]

            if x == target:
                return mid
            elif x > target:
                left = mid + 1
            else:
                right = mid - 1
        
        return -1

# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:
