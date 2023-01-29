# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

import collections

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None
        self.count = 1

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

class LFUCache:

    def __init__(self, capacity):
        self._size = 0
        self._capacity = capacity
        self._key_to_node = dict()
        self._min_frequency = 0
        # one for each frequency
        self._doubly_linked_lists = collections.defaultdict(DoublyLinkedList)

    def _make_space(self):
        node = self._doubly_linked_lists[self._min_frequency].pop()
        del self._key_to_node[node.key]
        self._size -= 1

    def _update(self, node):
        frequency = node.count
        # remove from old frequency linked list
        self._doubly_linked_lists[frequency].pop(node)
        if frequency == self._min_frequency and not self._doubly_linked_lists[frequency]:
            self._min_frequency += 1

        node.count += 1
        new_frequency = node.count
        # add to new frequency linked list
        self._doubly_linked_lists[new_frequency].append(node)

    def get(self, key):
        if key not in self._key_to_node:
            return -1
        node = self._key_to_node[key]
        self._update(node)
        return node.value

    def put(self, key, value):
        if self._capacity == 0:
            return

        if key in self._key_to_node:
            node = self._key_to_node[key]
            self._update(node)
            node.value = value
        else:
            if self._size == self._capacity:
                self._make_space()
            # add new node
            node = Node(key, value)
            self._key_to_node[key] = node
            self._doubly_linked_lists[1].append(node)
            self._min_frequency = 1
            self._size += 1
