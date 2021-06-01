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
    vector<string> findRepeatedDnaSequences(string dna) {
        if(dna.size()<10) return {};

        int size = dna.size(); 
        string sequence;
        map<string,int> sequenceCount;
        vector<string> repeatedSequences;

        for(int i=0; i<size-9; i++) {
            sequence = dna.substr(i, 10);
            sequenceCount[sequence]++;
        }
        
        for(auto entry : sequenceCount) 
            if(entry.second>1) repeatedSequences.push_back(entry.first);
        
        return repeatedSequences;
    }
};