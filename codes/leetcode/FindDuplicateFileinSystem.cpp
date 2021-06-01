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
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        string root, content, file;
        unordered_map<string, vector<string>> files;

        for (auto entry : paths) {            
            for(int i=0, j=0, k=0, l=1; i<entry.size(); i++) {
                if(entry[i] == ' ' && l==1) {
                    j = i+1;
                    k = 0;
                    l = 0;
                    root = entry.substr(0, i);
                }
                else if(entry[i] == '(') {
                    k = i+1;
                }
                else if(entry[i] == ')') {
                    file = root + '/' + entry.substr(j, k-j-1);
                    content = entry.substr(k, i-k);
                    if(files.find(content) == files.end())
                        files[content] = vector<string>();
                    files[content].push_back(file);
                    j = i+2;
                }
            }
        }
        
        vector<vector<string>> duplicates;
        for(auto entry : files) {
            if (entry.second.size()>1) 
                duplicates.push_back(entry.second);
        }
        return duplicates;
    }
};