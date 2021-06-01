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
    int bitwiseComplement(int N) {
        return (N==0) ? 1 : ~N&((1<<((int)log2((double)N)+1))-1);
    }
};