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
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int poisoned = 0, till = 0;
        for(int time : timeSeries) {
            poisoned += (time>till) ? duration : (duration-(till-time));
            till = time+duration;
        }
        return poisoned;
    }
};