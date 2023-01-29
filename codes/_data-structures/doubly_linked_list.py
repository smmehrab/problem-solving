# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class DoublyLinkedList:

    def __init__(self):
        self._length = 0
        self._end = Node(None, None)
        self._end.prev = self._end
        self._end.next = self._end

    def __len__(self):
        return self._length
    
    def append(self, node):
        node.next = self._end.next
        node.prev = self._end
        node.next.prev = node
        self._end.next = node
        self._length += 1

    def pop(self, node=None):
        if self._length == 0:
            return
        if not node:
            node = self._end.prev
        node.prev.next = node.next
        node.next.prev = node.prev
        self._length -= 1
        return node
