class Solution {
private:
    int n;
    vector<int> numbers;
    vector<int> indexMap;
    vector<int> result;

    void merge(int low, int mid, int high) {
        vector<int> changedIndexMap;
        int i = low, j = mid+1, inverseCount = 0;

        while (i <= mid && j <= high) {
            if (numbers[indexMap[i]] <= numbers[indexMap[j]]) {
                result[indexMap[i]] += inverseCount;
                changedIndexMap.push_back(indexMap[i++]);
            } 
            else {
                inverseCount++;
                changedIndexMap.push_back(indexMap[j++]);
            }
        }

        while (i <= mid) {
            result[indexMap[i]] += inverseCount;
            changedIndexMap.push_back(indexMap[i++]);
        }

        while (j <= high) changedIndexMap.push_back(indexMap[j++]);
        move(changedIndexMap.begin(), changedIndexMap.end(), indexMap.begin()+low);
    }

    void mergeSort(int low, int high) {
        if (low<high) {
            int mid = (low+high)/2;
            mergeSort(low, mid);
            mergeSort(mid+1, high);
            merge(low, mid, high);
        }
    }

public:
    vector<int> countSmaller(vector<int>& numbers) {
        this->n = numbers.size();
        this->numbers = numbers;
        for(int i=0; i<n; i++) {
            this->indexMap.push_back(i);
            this->result.push_back(0);   
        }
        mergeSort(0, n-1);
        return result;
    }
};