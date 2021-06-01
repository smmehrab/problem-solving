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
private:
    int distance(vector<int>& p1, vector<int>& p2){
        return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
    }

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> uniqueDistances;
        uniqueDistances.insert(distance(p1, p2));
        uniqueDistances.insert(distance(p1, p3));
        uniqueDistances.insert(distance(p1, p4));
        uniqueDistances.insert(distance(p2, p3));
        uniqueDistances.insert(distance(p2, p4));
        uniqueDistances.insert(distance(p3, p4));
        return uniqueDistances.find(0)==uniqueDistances.end() && uniqueDistances.size()==2;
    }
};