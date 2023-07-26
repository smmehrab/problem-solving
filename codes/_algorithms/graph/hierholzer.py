# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

def find_degrees(graph):
    indegree = [0] * len(graph)
    outdegree = [0] * len(graph)

    for node, neighbors in enumerate(graph):
        outdegree[node] = len(neighbors)
        for neighbor in neighbors:
            indegree[neighbor] += 1

    return indegree, outdegree

def eulerian_check(graph):
    indegree, outdegree = find_degrees(graph)

    odd_indegree_count = 0
    odd_outdegree_count = 0
    start_node = None

    for node in range(len(graph)):
        if outdegree[node] - indegree[node] > 1 or indegree[node] - outdegree[node] > 1:
            return False, None
        elif outdegree[node] - indegree[node] == 1:
            odd_outdegree_count += 1
            start_node = node
        elif indegree[node] - outdegree[node] == 1:
            odd_indegree_count += 1
        elif indegree[node] != outdegree[node]:
            return False, None

    if odd_indegree_count == 1 and odd_outdegree_count == 1:
        return True, start_node
    elif odd_indegree_count == 0 and odd_outdegree_count == 0:
        for node in range(len(graph)):
            if outdegree[node]>0:
                start_node = node
                break
        return True, start_node

    return False, None

def hierholzer(graph, start_node=0):
    if len(graph) == 0:
        return
    euler = []
    stack = [start_node]
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

    is_eulerian, start_node = eulerian_check(graph)

    print("Eulerian Check: ")
    print(f"> {is_eulerian}")

    eulerian_path = hierholzer(graph, start_node)

    print("Eulerian Path:")
    print(f"> {eulerian_path}")
