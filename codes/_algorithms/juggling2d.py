# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Juggling2D:

    """
        [n x n] matrix
        in-place rotation algorithm
    """

    def __init__(self, matrix):
        self.matrix = matrix
        self.n = len(matrix)

    def rotate_clockwise(self, k):
        """
            rotates k times clockwise
            or (k*90) degrees clockwise
        """

        k = k%4
        if k==0:
            return self.matrix

        # x --> vertical
        # y --> horizontal

        DEBUG = False
        
        # k time rotation
        while k>0:
            k -= 1
            # 1 time rotation
            layer = self.n
            start_x = 0
            start_y = 0 
            while layer>1:
                    
                if DEBUG:
                    print("Layer: " + str(layer))
                    print("----------------------------")
                
                set_count = layer-1
                for set_index in range(set_count):
                    x, y = start_x, start_y+set_index
                    element = self.matrix[x][y]
                    
                    if DEBUG:
                        print("\nSet: " + str(start_y))
                        print(str(x) + " " + str(y) + " " +str(element))
                    
                    for _ in range(4):
                        x, y = start_x + ((y-start_y)+layer)%layer, start_y+(layer-1)-(x-start_x)
                        self.matrix[x][y], element = element, self.matrix[x][y]
                        if DEBUG:
                            print(str(x) + " " + str(y) + " " +str(element))
                                    
                if DEBUG:
                    print("\n----------------------------")
                
                layer -= 2
                start_x += 1
                start_y += 1

        return self.matrix

    def rotate_anticlockwise(self, k):
        """
            rotates k times anticlockwise
            or (k*90) degrees anticlockwise
        """

        k = k%4
        if k==0:
            return self.matrix
        return self.rotate_clockwise(4-k)
