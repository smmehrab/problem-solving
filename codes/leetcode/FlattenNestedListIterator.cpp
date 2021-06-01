/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> flattened;
    int index;
    void flatten(vector<NestedInteger> &nestedList) {
        for (auto nestedElement : nestedList) {
            if (nestedElement.isInteger()) flattened.push_back(nestedElement.getInteger());
            else flatten(nestedElement.getList());
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->index = 0;
        flatten(nestedList);  
    }
    
    int next() {
        return flattened[index++];
    }
    
    bool hasNext() {
        return index < flattened.size();
    }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */