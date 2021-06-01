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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int numberOfGasStations = gas.size() ;
        int gasLeftFrom0 = 0;
        int gasLeftFromStart = 0;
        int startIndex = 0;

        for (int i=0; i<numberOfGasStations; i++) {
            if (gas[i]>=cost[i] && gasLeftFromStart<0) {
                startIndex = i;
                gasLeftFromStart = 0;
            }
            gasLeftFrom0 += (gas[i]-cost[i]);
            gasLeftFromStart += (gas[i]-cost[i]);
        }
        
        return (gasLeftFromStart<0 || gasLeftFrom0<0) ? -1 : startIndex;
    }
};