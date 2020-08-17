class Solution
{
public:
    vector<int> findOrder(int courseCount, vector<vector<int>> &dependencies)
    {
        vector<int> result;
        vector<int> edges[courseCount];
        vector<int> inDegree(courseCount, 0);

        for (auto dependency : dependencies)
        {
            int dependent = dependency[0];
            int prerequisite = dependency[1];
            edges[prerequisite].push_back(dependent);
            inDegree[dependent]++;
        }

        queue<int> q;
        for (int course = 0; course < courseCount; course++)
        {
            if (inDegree[course] == 0)
            {
                q.push(course);
            }
        }

        while (!q.empty())
        {
            int course = q.front();
            result.push_back(course);
            q.pop();

            for (auto dependentCourse : edges[course])
            {
                inDegree[dependentCourse]--;
                if (inDegree[dependentCourse] == 0)
                {
                    q.push(dependentCourse);
                }
            }
        }

        if (result.size() == courseCount)
        {
            return result;
        }

        return vector<int>();
    }
};