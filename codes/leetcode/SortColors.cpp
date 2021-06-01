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
    void sortColors(vector<int>& colors) {
        int colorCount = colors.size();
        int redIndex=0, blueIndex = colorCount-1;
        for(int index=0; index<colorCount;){
            if(colors[index] == 0 && index>redIndex) swap(colors[index], colors[redIndex++]);
            else if(colors[index] == 2 && index<blueIndex) swap(colors[index], colors[blueIndex--]);
            else index++;
        }
    }
};