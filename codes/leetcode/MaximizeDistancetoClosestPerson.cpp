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
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size(), maxDistance = -1, neighbor=-1;
        for(int i=0; i<n; i++) {
            if(seats[i]==1) {
                if(neighbor==-1) {
                    neighbor = i;
                    if(i!=0) maxDistance = max(maxDistance, neighbor*2);
                }
                else {
                    maxDistance = max(maxDistance, (i-neighbor));
                    neighbor = i;
                }
            }
        }
        maxDistance = max(maxDistance, (n-1-neighbor)*2);
        return (maxDistance/2);
    }
};