# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Node:
	def __init__(self, value):
		self.value = value
		self.next = None

class Stack:

	def __init__(self):
		self.head = Node("head")
		self.__size = 0

	def __str__(self):
		node = self.head.next
		result = ""
		while node:
			result += str(node.value) + "->"
			node = node.next
		return result[:-3]

	def size(self):
		return self.__size

	def empty(self):
		return self.__size == 0

	def peek(self):
		if self.empty():
			raise Exception("Can't Peek from Empty Stack")
		return self.head.next.value

	def push(self, value):
		node = Node(value)
		node.next = self.head.next
		self.head.next = node
		self.__size += 1

	def pop(self):
		if self.empty():
			raise Exception("Can't Pop from Empty Stack")
		node = self.head.next
		self.head.next = self.head.next.next
		self.__size -= 1
		return node.value

class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = Stack()
        for c in s:
            if stack.empty() or stack.peek()!=c:
                stack.push(c)
            elif stack.peek()==c:
                stack.pop()
        set_s = ""
        while not stack.empty():
            set_s += stack.pop()
        set_s = set_s[::-1]
        return set_s

