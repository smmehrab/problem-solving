# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class ProductProcessor:

    def __init__(self):
        pass

    def prefix(self, arr):
        n = len(arr)
        for i in range(1, n):
            arr[i] = arr[i] * arr[i-1]

    def postfix(self, arr):
        n = len(arr)
        for i in range(n-2, -1, -1):
            arr[i] = arr[i] * arr[i+1]
            
class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        pre = [num for num in nums]
        post = [num for num in nums]

        product_processor = ProductProcessor()
        product_processor.prefix(pre)
        product_processor.postfix(post)
        
        # print(pre)
        # print(post)
        
        answer = []
        for index, num in enumerate(nums):
            if index == 0:
                answer.append(post[index+1])
            elif index == n-1:
                answer.append(pre[index-1])
            else:
                answer.append(pre[index-1]*post[index+1])
        
        return answer
