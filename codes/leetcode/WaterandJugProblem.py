class Solution(object):

    def findGCD(self, a, b):
        while b:
            a, b = b, a%b
        return a

    def canMeasureWater(self, jug1Capacity, jug2Capacity, targetCapacity):
        """
        :type jug1Capacity: int
        :type jug2Capacity: int
        :type targetCapacity: int
        :rtype: bool
        """

        if targetCapacity <= (jug1Capacity+jug2Capacity):
            gcd = self.findGCD(jug1Capacity, jug2Capacity)
            if targetCapacity%gcd==0:
                return True
        return False
