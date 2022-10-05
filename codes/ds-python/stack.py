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
