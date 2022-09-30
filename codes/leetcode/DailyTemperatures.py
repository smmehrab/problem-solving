# ************************************************
# username    :   smmehrab
# fullname    :   s.m.mehrabul islam
# email       :   mehrab.24csedu.001@gmail.com
# institute   :   university of dhaka, bangladesh
# session     :   2017-2018
# ************************************************

class Node:
	def __init__(self, value):
		self.value = value
		self.next = None

class Stack:

	def __init__(self):
		self.head = Node("head")
		self.size = 0

	def __str__(self):
		node = self.head.next
		result = ""
		while node:
			result += str(node.value) + "->"
			node = node.next
		return result[:-3]

	def getSize(self):
		return self.size

	def isEmpty(self):
		return self.size == 0

	def peek(self):
		if self.isEmpty():
			raise Exception("Can't Peek from Empty Stack")
		return self.head.next.value

	def push(self, value):
		node = Node(value)
		node.next = self.head.next
		self.head.next = node
		self.size += 1

	def pop(self):
		if self.isEmpty():
			raise Exception("Can't Pop from Empty Stack")
		node = self.head.next
		self.head.next = self.head.next.next
		self.size -= 1
		return node.value

class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        
        n = len(temperatures)
        answers = [0]*n
        stack = Stack()
        for index, temperature in enumerate(temperatures):
            while not stack.isEmpty() and temperature>temperatures[stack.peek()]:
                left = stack.peek()
                answers[left] = index-left
                stack.pop()
            stack.push(index)
        return answers
