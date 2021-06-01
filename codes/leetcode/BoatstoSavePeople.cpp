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
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int light = 0, heavy = people.size()-1, boats = 0;

        while (light <= heavy) {
            if (people[light] + people[heavy] <= limit) light++;
            heavy--;
            boats++;
        }

        return boats;
    }
};