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
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """

        DEBUG = False
        
        # so that we get to pop the entire stack (guarantee)
        # even if the heights are in increasing order
        heights.append(0)
        
        area = 0
        stack = Stack()
        for index, height in enumerate(heights):
            left_index = index

            if DEBUG:
                print('{:15s}{:15s}'.format("index: " + str(index),"height: " + str(height)))
                print("------------------------------------------------")
                if not stack.isEmpty() and height < stack.peek()[1]:
                    print('{:15s}{:15s}{:10s}'.format("left_index","left_height","area"))
                else:
                    print("increasing...")
        
            while not stack.isEmpty() and height < stack.peek()[1]:
                left_index, left_height = stack.peek()
                area = max(area, (index-left_index)*left_height)
                stack.pop()

                if DEBUG:
                    print('{:15s}{:15s}{:10s}'.format(str(left_index),str(left_height),str((index-left_index)*left_height)))
            
            stack.push((left_index, height))

            if DEBUG:
                print("------------------------------------------------")

        return area