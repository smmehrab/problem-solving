# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def get_root(self, n, leftChild, rightChild):
        all_children = set(leftChild) | set(rightChild)
        print(all_children)
        root = -1
        for i in range(n):
            if i not in all_children:
                print(i)
                root = i
                break
        return root

    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        root = self.get_root(n, leftChild, rightChild)
        if root == -1:
            return False
        
        visited = {root}
        stack = [root]
        while stack:
            node = stack.pop()
            children = [leftChild[node], rightChild[node]]
            for child in children:
                if child == -1:
                    continue
                if child in visited:
                    return False
                stack.append(child)
                visited.add(child)
        return len(visited) == n