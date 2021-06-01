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
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [] (vector<int> &a, vector<int> &b) {
            return a[1]==b[1] ? a[0]<b[0] : a[1]<b[1];
        });
        
        // O (n*n)
        //         int n = courses.size();
        //         int time=0, courseTaken=0;
        //         for (int i=0; i<n; i++) {
        //             if (time+courses[i][0] <= courses[i][1]) {
        //                 time += courses[i][0];
        //                 courses[courseTaken++] = courses[i];
        //             } 

        //             else {
        //                 int courseWithMaximumDurationSoFar = i;
        //                 for (int j=0; j<courseTaken; j++) {
        //                     if (courses[j][0] > courses[courseWithMaximumDurationSoFar][0])
        //                         courseWithMaximumDurationSoFar = j;
        //                 }
        //                 if (courses[courseWithMaximumDurationSoFar][0] > courses[i][0]) {
        //                     time += courses[i][0]-courses[courseWithMaximumDurationSoFar][0];
        //                     courses[courseWithMaximumDurationSoFar] = courses[i];
        //                 }
        //             }
        //         }

        //         return courseTaken;
        
        // O (nLogn)
        priority_queue<int> pq;
        int time = 0;
        for (vector<int> course : courses) {
            if (time+course[0] <= course[1]) {
                time += course[0];
                pq.push(course[0]);                
            }
            else if (!pq.empty() && pq.top()>course[0]) {
                time += course[0]-pq.top(); 
                pq.pop();
                pq.push(course[0]);
            }
        }
        return pq.size();
    }
};