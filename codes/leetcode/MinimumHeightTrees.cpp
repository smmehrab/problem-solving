/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution { 
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n<2) return {0};
        
        vector<vector<int>> graph(n);
        vector<int> degrees(n, 0);
        for(vector<int> edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }        
     
        vector<int> leafNodes, nextLeafNodes;
        for(int node=0; node<=n-1; node++)
            if(degrees[node] == 1) 
                leafNodes.push_back(node);

        while(!leafNodes.empty()) {
            nextLeafNodes.clear();
            for(int leafNode : leafNodes) 
                for(int neighbor: graph[leafNode])
                    if(--degrees[neighbor] == 1)
                        nextLeafNodes.push_back(neighbor);

            if(nextLeafNodes.empty()) break;
            leafNodes = nextLeafNodes;
        }

        return leafNodes;
    }
};