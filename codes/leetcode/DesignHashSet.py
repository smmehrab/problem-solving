# ************************************************
# username    :   smmehrab
# fullname    :   s.m.mehrabul islam
# email       :   mehrab.24csedu.001@gmail.com
# institute   :   university of dhaka, bangladesh
# session     :   2017-2018
# ************************************************

class Node:
    def __init__(self, val, next=None) -> None:
        self.val = val
        self.next = next

class MyHashSet:

    def __init__(self):
        self._size = 1000000
        self._set = [Node(0) for _ in range(10000)]

    def add(self, key: int) -> None:
        index = key % self._size
        node = self._set[index]
        while node.next:
            if node.next.val == key:
                return
            node = node.next
        node.next = Node(key)

    def remove(self, key: int) -> None:
        index = key % self._size
        node = self._set[index]
        while node.next:
            if node.next.val == key:
                node.next = node.next.next
                return
            node = node.next

    def contains(self, key: int) -> bool:
        index = key % self._size
        node = self._set[index]
        while node.next:
            if node.next.val == key:
                node.next = node.next.next
                return True
            node = node.next
        return False

# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)