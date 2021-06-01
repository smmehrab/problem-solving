/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution
{

private:
    void dfs(vector<vector<int>> &graph, int source, int destination, vector<vector<int>> &result, vector<int> &currentPath, vector<bool> &visited)
    {
        if (source == destination)
        {
            currentPath.push_back(source);
            result.push_back(currentPath);

            currentPath.pop_back();
            return;
        }

        visited[source] = true;
        currentPath.push_back(source);

        for (int i = 0; i < graph[source].size(); i++)
            if (!visited[graph[source][i]])
                dfs(graph, graph[source][i], destination, result, currentPath, visited);

        currentPath.pop_back();
        visited[source] = false;
        return;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> result;
        vector<int> currentPath;
        vector<bool> visited(graph.size(), false);
        dfs(graph, 0, graph.size() - 1, result, currentPath, visited);
        return result;
    }
};