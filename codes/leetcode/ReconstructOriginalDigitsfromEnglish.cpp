class Solution {
    static constexpr pair<char, int> digChars[10] = {{'z', 0}, {'w', 2}, {'x', 6}, {'s', 7}, {'g', 8}, {'h', 3}, {'v', 5}, {'f', 4}, {'o', 1}, {'e', 9}};
    static string digWord[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
public:
    string originalDigits(string s) {
        // support variables
        int digits[10], tot = 0;
        char alpha[123] = {};
        // populating alpha
        for (char c: s) 
            alpha[c]++;
        for (auto d: digChars) {
            // getting the number of matches
            int n = alpha[d.first];
            // updating digits with the number of matches
            digits[d.second] = n;
            // updating tot by the number of needed characters
            tot += n * digWord[d.second].size();
            // clearing up alpha accordingly
            for (char c: digWord[d.second]) 
                alpha[c] -= n;
        }
        // creating and populating res
        string res(tot, '*');
        for (int i = 0, j = 0; i < 10; i++) {
            while(digits[i]--) {
                for (char c: digWord[i]) res[j++] = c;
            }
        }
        return res;
    }
};