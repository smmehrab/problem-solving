class Solution {
public:
    void rotate(vector<int>& numbers, int k) {
        int n = numbers.size(), currentIndex, currentValue, nextIndex, temp;
        k %= n;
        for (int index=0, replacementCount=0; replacementCount<n; index++) {
          currentIndex = index;
          currentValue = numbers[index];
          do {
            nextIndex = (currentIndex+k)%n;
            temp = numbers[nextIndex];
            numbers[nextIndex] = currentValue;

            currentIndex = nextIndex;
            currentValue = temp;
            replacementCount++;
          } while (currentIndex != index);
        }
    }
};