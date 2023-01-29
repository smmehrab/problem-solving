# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class CountSorter:

    def __init__(self) -> None:
        pass

    def sort(self, values:list) -> list:
        
        n = len(values)
        vmax = int(max(values))
        vmin = int(min(values))
        vrange = vmax-vmin+1

        # init
        count = [0]*vrange
        output = [0]*n

        # count
        for value in values:
            count[value-vmin] += 1
    
        # cumulative count
        for index in range(1, vrange):
            count[index] += count[index-1]

        # sorted placement (reverse)
        for index in range(len(values)-1, -1, -1):
            cindex = values[index]-vmin
            oindex = count[cindex]-1
            output[oindex] = values[index]
            count[cindex] -= 1

        return output
