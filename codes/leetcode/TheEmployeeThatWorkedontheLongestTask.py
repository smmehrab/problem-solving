# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def hardestWorker(self, n, logs):
        """
        :type n: int
        :type logs: List[List[int]]
        :rtype: int
        """
        
        longest_task_employee = -1
        longest_task = -1
        previous_time = 0
        
        for log in logs:
            employee, time = log
            task = time - previous_time
            if task == longest_task:
                longest_task_employee = min(longest_task_employee, employee)
            if task > longest_task:
                longest_task = task
                longest_task_employee = employee
        
            previous_time = time
        return longest_task_employee