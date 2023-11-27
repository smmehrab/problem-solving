#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> f;

int get_zeros(string s) {
    int count = 0;
    for (char c : s) {
        if (c == '0')
            count++;
    }
    return count;
}

int main() {
    int n, m, k, frequency, zeros;
    char c;
    string row_string;

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        row_string = "";
        for(int j = 0; j < m; j++) {
            cin >> c;
            row_string += c;
        }
        f[row_string]++;
    }

    int ans = 0;
    for (auto entry : f) {
        row_string = entry.first;
        frequency = entry.second;
        zeros = get_zeros(row_string);
        if(zeros > 0 && zeros <= k && (k % zeros == 0))
            ans = max(ans, frequency);
    }

    cout << ans << endl;
    return 0;
}
