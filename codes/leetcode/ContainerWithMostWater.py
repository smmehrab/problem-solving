class Solution(object):
    def maxArea(self, heights):
        """
        :type height: List[int]
        :rtype: int
        """
        
        n = len(heights)
        left = 0
        right = n-1
        water = -1
        
        while(left<right):
            water = max(water, min(heights[left], heights[right])*(right-left))
            if heights[left] < heights[right]:
                left += 1
            else:
                right -= 1
        
        return water
