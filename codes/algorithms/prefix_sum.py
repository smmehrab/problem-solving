# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class PrefixSum:

    """
        algorithm to find prefix sum of specific data-structure
    """

    def __init__(self):
        pass

    def array(self, arr):
        n = len(arr)
        for i in range(1, n):
            arr[i] = arr[i] + arr[i-1]

    def matrix(self, mat):
        n = len(mat)
        m = len(mat[0])

        # first row
        for y in range(1, m):
            mat[0][y] = mat[0][y] + mat[0][y-1]

        # first col
        for x in range(1, n) :
            mat[x][0] = mat[x][0] + mat[x-1][0]

        # rest
        for x in range(1, n) :
            for y in range(1, m) :
                mat[x][y] = mat[x][y] + (mat[x-1][y] + mat[x][y-1] - mat[x-1][y-1])
