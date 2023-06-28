# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:

        # Build Graph
        graph = defaultdict(list)
        for i, (u, v) in enumerate(edges):
            graph[u].append((v, succProb[i]))
            graph[v].append((u, succProb[i]))

        # Dijsktra's Algorithm
        max_p_to_reach = [0.0] * n
        max_p_to_reach[start] = 1.0
        pq = [(-1, start)]
        while pq:
            p, node = heapq.heappop(pq)
            p *= -1

            if node == end:
                return p

            for next_node, next_p in graph[node]:
                p_to_reach_next_node = (p * next_p)
                if p_to_reach_next_node > max_p_to_reach[next_node]:
                    max_p_to_reach[next_node] = p_to_reach_next_node
                    heapq.heappush(pq, ((-1)*p_to_reach_next_node, next_node))

        return 0