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
    string reorganizeString(string s) {
        string newS = "";

        map<char, int> counter;
        for(char x : s)
            counter[x]++;
        
        priority_queue<pair<int, char>> heap;        
        for(auto entry : counter)
            heap.push({entry.second, entry.first});
        
        while(heap.size()>1) {
            auto a = heap.top();
            heap.pop();
            
            newS += a.second;
            a.first--;
            
            auto b = heap.top();
            heap.pop();
            
            newS += b.second;
            b.first--;
            
            if(a.first>0)
                heap.push(a);
            if(b.first>0)
                heap.push(b);
        }
        
        
        if(heap.size()>0)
            newS = (heap.top().first>1) ? "" : newS + heap.top().second;
        return newS;
    }
};