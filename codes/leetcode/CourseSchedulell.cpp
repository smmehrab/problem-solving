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
    vector<int> findOrder(int numberOfCourses, vector<vector<int>> &prerequisites) {
        vector<int> ordering;
        vector<int> graph[numberOfCourses];
        vector<int> prerequisiteCount(numberOfCourses, 0);

        for (auto prerequisite : prerequisites) {
            prerequisiteCount[prerequisite[0]]++;
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }

        queue<int> takeableCourses;
        for(int course=0; course<numberOfCourses; course++) 
            if(prerequisiteCount[course]==0) 
                takeableCourses.push(course);
      
        while(!takeableCourses.empty()) {
            int currentCourse = takeableCourses.front();
            ordering.push_back(currentCourse);
            takeableCourses.pop();
            for(int dependentCourse : graph[currentCourse]) 
                if(--prerequisiteCount[dependentCourse]==0) 
                    takeableCourses.push(dependentCourse);
        }

        return (ordering.size() == numberOfCourses) ? ordering : vector<int>();
    }
};