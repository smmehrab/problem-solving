# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Juggling:

    """
        in place array rotation algorithm
        O(n)
    """

    def gcd(self, a, b):   
        while(b):
            a, b = b, a % b
        return abs(a)

    def __init__(self, arr):
        self.arr = arr
        self.n = len(arr)

    def rotate_left(self, k):
        """
            rotates k times to the left
        """
        if k==0 or k==self.n:
            return self.arr
        
        set_count = self.gcd(self.n, k)
        for set_start in range(set_count):
            start_element = self.arr[set_start]
            index = set_start
            next_index = (index+k)%self.n
            while next_index>index:
                self.arr[index] = self.arr[next_index]
                index = next_index
                next_index = (index+k)%self.n
            self.arr[index] = start_element

        return self.arr

    def rotate_right(self, k):
        """
            rotates k times to the right
        """
        if k==0 or k==self.n:
            return self.arr
        
        set_count = self.gcd(self.n, k)
        element_count = self.n//set_count
        
        for set_start in range(set_count):
            index = set_start
            element = self.arr[index]
            for _ in range(element_count):
                index = (index+k)%self.n
                self.arr[index], element = element, self.arr[index]
            self.arr[set_start] = self.arr[index]

        return self.arr


class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        juggling = Juggling(nums)
        juggling.rotate_right(k)