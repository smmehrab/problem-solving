class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> permutation; 

        multiset<int> mSet;
        for(int number : A)
            mSet.insert(number);
        
        for(int number : B) {
            auto smallestGreater = mSet.upper_bound(number);
            if(smallestGreater == mSet.end())
                smallestGreater = mSet.begin();
            permutation.push_back(*smallestGreater);
            mSet.erase(smallestGreater);
        }
        
        return permutation;
    }
};