class Solution(object):
    def trap(self, height):
        """
        :type heights: List[int]
        :rtype: int
        """

        # Algorithm
        #------------------------------------------------
        # water_i = min(maxLeft, maxRight) - heights[i]
        # if water_i>0:
        #       water += water_i
        # else:
        #       water += 0
        #------------------------------------------------

        if not height:
            return 0

        n = len(height)
        water = 0
        left = 0
        right = n-1
        maxLeft = height[left]
        maxRight = height[right]

        # two pointer
        while left<right:
            if maxLeft<=maxRight:
                left += 1
                maxLeft = max(maxLeft, height[left])
                water += maxLeft - height[left]
            else:
                right -= 1
                maxRight = max(maxRight, height[right])
                water += maxRight - height[right]

        return water
