# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

def hierholzer(graph):
    if len(graph) == 0:
        return
    euler = []
    stack = [0]
    while stack:
        node = stack[-1]
        if graph[node]:
            next_node = graph[node].pop()
            stack.append(next_node)
        else:
            euler.append(stack.pop())
    return euler[::-1]


if __name__ == "__main__":

    graph = [[] for _ in range(7)]

    graph[0].append(1)
    graph[0].append(6)
    graph[1].append(2)
    graph[2].append(0)
    graph[2].append(3)
    graph[3].append(4)
    graph[4].append(2)
    graph[4].append(5)
    graph[5].append(0)
    graph[6].append(4)
    
    eulerian_path = hierholzer(graph)
    print(eulerian_path)
