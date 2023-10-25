# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   201761s4964
# ************************************************

class Solution:
    def search_in_binary_tree(self, n: int, k: int, root_val: int) -> int:
        # base case
        if n == 1:
            return root_val

        # search pivot
        number_of_nodes = 2 ** (n - 1)
        mid = (number_of_nodes / 2)

        # right subtree
        if k > mid:
            # 0 --> 01
            root_val = 1-root_val
            return self.search_in_binary_tree(n-1, k-mid, root_val)
        # left subtree
        else:
            # 1 --> 10
            return self.search_in_binary_tree(n - 1, k, root_val)

    def kthGrammar(self, n: int, k: int) -> int:
        return self.search_in_binary_tree(n, k, 0)
