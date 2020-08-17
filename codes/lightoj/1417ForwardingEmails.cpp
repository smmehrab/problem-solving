#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<map>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

void findMaxReach(int n, const vector<int>& child, vector<int>& maxReach){
    for (int i = 0; i < n; ++i){
        if (maxReach[i] == -1){

            int current = i;

            vector<int> orderOfTraversal;
            vector<bool> reached(n, false);

            while (maxReach[current] == -1 && !reached[current]){
                reached[current] = true;
                orderOfTraversal.push_back(current);
                current = child[current];
            }

            // IF WE REACH A NODE WITH KNOWN MAX REACH
            if (maxReach[current] != -1){
                int reachCount = orderOfTraversal.size();
                for (int pos = reachCount - 1; pos >= 0; --pos)
                    maxReach[orderOfTraversal[pos]] = maxReach[current] + (reachCount - pos);
            }

            // IF THERE IS A CYCLE
            else if(reached[current]){
                int currentPosInOrder;

                // FINDING, FROM WHERE THE CYCLE HAS STARTED
                for (currentPosInOrder = 0; orderOfTraversal[currentPosInOrder] != current; ++currentPosInOrder);

                // FINDING THE LENGTH OF THAT CYCLE
                int sizeOfCycle = orderOfTraversal.size() - currentPosInOrder;

                // ASSIGNING ALL THE NODES OF THE CYCLE WITH THE SAME MAX REACH = SIZE OF THAT CYCLE
                for (int pos = currentPosInOrder; pos < orderOfTraversal.size(); ++pos)
                    maxReach[orderOfTraversal[pos]] = sizeOfCycle;

                // ASSIGNING THE NODES OUTSIDE THE CYCLE WITH MAX REACH = SIZE OF THAT CYCLE + THEIR DISTANCE FROM THAT CYCLE
                for (int pos = 0; pos < currentPosInOrder; ++pos)
                    maxReach[orderOfTraversal[pos]] = sizeOfCycle + (currentPosInOrder - pos);
            }
        }
    }
}


int main(){
    int t, cs = 0, n, u, v, bestNode;
    cin >> t;

    while(t--){
        cin >> n;

        vector<int> child(n);
        vector<int> maxReach(n, -1);

        for (int i = 0; i < n; ++i){
            cin >> u >> v;
            child[--u] = --v;
        }

        findMaxReach(n, child, maxReach);

        bestNode = 0;
        for (int i = 0; i < n; ++i){
            if (maxReach[i] > maxReach[bestNode])
                bestNode = i;
        }

        cout << "Case " << ++cs << ": " << ++bestNode << endl;
    }
}
