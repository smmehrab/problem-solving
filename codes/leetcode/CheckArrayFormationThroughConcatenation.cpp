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
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size(), p = pieces.size();
        if(n==1 && n==p) return arr[0] == pieces[0][0];

        map<int, int> indexOf;
        for(int i=0; i<n; i++) indexOf[arr[i]] = i;
        
        bool answer = true;
        for(vector<int> piece : pieces) {
            p = piece.size();
            for(int i=0; i<p-1; i++){
                if(indexOf[piece[i]]+1 != indexOf[piece[i+1]]) {
                    answer = false;
                    break;
                }
            }
        }
        
        return answer;
    }
};