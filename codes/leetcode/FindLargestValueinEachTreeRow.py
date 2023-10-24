# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        largest_values = []

        if not root:
            return largest_values

        queue = deque()
        queue.append(root)
        while queue:
            largest_value = float("-inf")
            number_of_nodes_in_a_level = len(queue)
            while number_of_nodes_in_a_level > 0:
                node = queue.popleft()
                largest_value = max(largest_value, node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                number_of_nodes_in_a_level -= 1
            largest_values.append(largest_value)

        return largest_values