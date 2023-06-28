# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from typing import List

class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        # Sort Robots by Positions
        n = len(positions)
        robots = [i for i in range(n)]
        robots.sort(key=lambda x: positions[x])
        # Remove Collided Robots
        stack = []
        for robot1 in robots:
            if directions[robot1] == 'L':
                died = False
                while stack and not died:
                    robot2 = stack[-1]
                    if healths[robot1] == healths[robot2]:
                        healths[robot1] = healths[robot2] = 0
                        stack.pop()
                        died = True
                    elif healths[robot1] > healths[robot2]:
                        healths[robot1] -= 1
                        healths[robot2] = 0
                        stack.pop()
                    else:
                        healths[robot1] = 0
                        healths[robot2] -= 1
                        died = True
            else:
                stack.append(robot1)
        # Return Survived Robots
        survived_robots = []
        for robot in healths:
            if robot > 0:
                survived_robots.append(robot)
        return survived_robots