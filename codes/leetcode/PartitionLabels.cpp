class Solution {
public:
    vector<int> partitionLabels(string label){
        int numberOfLetters = label.size();
        unordered_map<char, int> lastOccurrence;
        for (int i = 0; i < numberOfLetters; i++) lastOccurrence[label[i]] = i;

        vector<int> partitions;
        int start=0, end=0, previousEnd=0;
        while (start < numberOfLetters){
            end = max(lastOccurrence[label[start]], end);
            if (start == end){
                partitions.push_back(end-previousEnd+1);
                previousEnd = end+1;
            }
            start++;
        }

        return partitions;
    }
};