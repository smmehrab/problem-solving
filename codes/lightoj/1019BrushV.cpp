/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
using namespace std;
 
int junctionCount, roadCount;
vector<pair<int, int> > roads[200];
int minimumDistance[200];
 
struct Node{
    int junction, distance;
    Node(int j, int d){
        junction=j;
        distance=d;
    }
    bool operator < (const Node & p)const{
        return p.distance<distance;
    }
};
 
int dijkstra(int source, int destination){
    priority_queue<Node> priority;
 
    for(int junction=1; junction<=junctionCount; junction++){
        minimumDistance[junction] = INT_MAX;
    }
 
    minimumDistance[source]=0;
    priority.push(Node(source, 0));
 
    while(!priority.empty()){
        Node current=priority.top();
        priority.pop();
 
        int currentJunction = current.junction;
        for(int index=0; index<roads[currentJunction].size(); index++){
            int nextJunction = roads[currentJunction][index].first;
            int nextDistance = roads[currentJunction][index].second;
 
            if(minimumDistance[nextJunction]>minimumDistance[currentJunction]+nextDistance){
                minimumDistance[nextJunction]=minimumDistance[currentJunction]+nextDistance;
                priority.push(Node(nextJunction, minimumDistance[nextJunction]));
            }
        }
    }
 
    return minimumDistance[destination];
}
 
int main(){
    int testCaseCount, source, destination, distance, answer;
    scanf("%d", &testCaseCount);
 
    for(int testCase=1; testCase<=testCaseCount; testCase++){
        scanf("%d %d", &junctionCount, &roadCount);
        for(int road=1; road<=roadCount; road++){
            scanf("%d %d %d", &source, &destination, &distance);
            roads[source].push_back(make_pair(destination, distance));
            roads[destination].push_back(make_pair(source, distance));
        }
 
        answer = dijkstra(1, junctionCount);
 
        if(answer==INT_MAX){
            printf("Case %d: Impossible\n", testCase, answer);
        }
        else{
            printf("Case %d: %d\n", testCase, answer);
        }
       
        for(int junction=0; junction<=junctionCount; junction++){
            roads[junction].clear();
        }
    }
 
    return 0;
}