#include <bits/stdc++.h>
using namespace std;

int junctionCount, roadCount;
vector<pair<int, int>> roads[2000];
int minimumDistance[2000];

struct Node
{
    int junction, distance;
    Node(int j, int d)
    {
        junction = j;
        distance = d;
    }
    bool operator<(const Node &p) const
    {
        return p.distance < distance;
    }
};

void dijkstra(int source)
{
    priority_queue<Node> priority;

    for (int junction = 0; junction < junctionCount; junction++)
    {
        minimumDistance[junction] = INT_MAX;
    }

    minimumDistance[source] = 0;
    priority.push(Node(source, 0));

    while (!priority.empty())
    {
        Node current = priority.top();
        priority.pop();

        int currentJunction = current.junction;
        for (int index = 0; index < roads[currentJunction].size(); index++)
        {
            int nextJunction = roads[currentJunction][index].first;
            int nextDistance = roads[currentJunction][index].second;

            if (minimumDistance[nextJunction] > max(minimumDistance[currentJunction], nextDistance))
            {
                minimumDistance[nextJunction] = max(minimumDistance[currentJunction], nextDistance);
                priority.push(Node(nextJunction, minimumDistance[nextJunction]));
            }
        }
    }
}

int main()
{
    int testCaseCount, source, destination, distance, answer;
    scanf("%d", &testCaseCount);

    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d %d", &junctionCount, &roadCount);
        for (int road = 0; road < roadCount; road++)
        {
            scanf("%d %d %d", &source, &destination, &distance);
            roads[source].push_back(make_pair(destination, distance));
            roads[destination].push_back(make_pair(source, distance));
        }

        scanf("%d", &source);

        dijkstra(source);

        printf("Case %d:\n", testCase);
        for (int junction = 0; junction < junctionCount; junction++)
        {
            if (minimumDistance[junction] == INT_MAX)
            {
                printf("Impossible\n");
            }
            else
            {
                printf("%d\n", minimumDistance[junction]);
            }
            roads[junction].clear();
        }
    }

    return 0;
}