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
    int lengthLongestPath(string path) {
        path.push_back('\n');

        vector<int> lengths(10000, 0);
        int currentLevel = 0, longestPath = 0, currentLength = 0;
        bool isLeaf = false;
            
        for(char character : path){
            switch(character){
                case '\n': 
                    currentLevel = 0; 
                    currentLength = 0; 
                    isLeaf = false; 
                    break; 
                case '\t': 
                    currentLevel++; 
                    break;
                case '.' : 
                    isLeaf = true;
                default:
                    currentLength++;
                    lengths[currentLevel] = currentLength;
                    if(isLeaf) longestPath = max(longestPath, accumulate(lengths.begin(), lengths.begin() + currentLevel + 1, 0) + currentLevel);
            }
        }
        
        return longestPath;
    }
};