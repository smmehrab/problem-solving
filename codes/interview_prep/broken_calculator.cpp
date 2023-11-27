#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

int ans = INT_MAX;

void getMinSteps(int target, unordered_map<int, int>& output, int cur_level,
                 vector<int>& workingNumber, int o, int signs[]) {
    if (workingNumber.empty()) {
        return;
    }

    for (int i = 0; i < workingNumber.size(); i++) {
        int cur_ele = workingNumber[i];
        workingNumber.erase(workingNumber.begin() + i);
        unordered_map<int, int> new_output;
        new_output[cur_ele] = 1;

        for (auto& entry : output) {
            int val = entry.first;
            int level = entry.second;

            if (signs[0] == 1) {
                int newAdd = cur_ele + val;
                int newFreq = level + 3;
                if (!new_output.count(newAdd) || new_output[newAdd] > newFreq) {
                    new_output[newAdd] = newFreq;
                }
                if (newAdd == target && newFreq <= o) {
                    ans = min(ans, newFreq);
                }
            }
            // Similar logic for subtraction, multiplication, division, and concatenation

            // Adding the original string
            int newAdd = stoi(to_string(cur_ele) + to_string(val));
            int newFreq = level + 1;
            if (!new_output.count(newAdd) || new_output[newAdd] > newFreq) {
                new_output[newAdd] = newFreq;
            }
            if (newAdd == target && newFreq <= o) {
                ans = min(ans, newFreq);
            }

            // Adding the reverse string
            newAdd = stoi(to_string(val) + to_string(cur_ele));
            if (!new_output.count(newAdd) || new_output[newAdd] > newFreq) {
                new_output[newAdd] = newFreq;
            }
            if (newAdd == target && newFreq <= o) {
                ans = min(ans, newFreq);
            }
        }

        for (auto& entry : output) {
            int val = entry.first;
            int level = entry.second;
            if (!new_output.count(val) || new_output[val] > level) {
                new_output[val] = level;
            }
        }

        getMinSteps(target, new_output, cur_level + 1, workingNumber, o, signs);
        workingNumber.insert(workingNumber.begin() + i, cur_ele);
    }
}

int main() {
    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m, o;
        cin >> n >> m >> o;

        vector<int> workingNumber(n);
        for (int i = 0; i < n; i++) {
            cin >> workingNumber[i];
        }

        int signs[4] = {0}; // Initialize signs array with zeros
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            signs[num - 1] = 1;
        }

        int target;
        cin >> target;

        unordered_map<int, int> output;
        getMinSteps(target, output, 1, workingNumber, o, signs);

        cout << ans << endl;
        ans = INT_MAX; // Reset ans for the next test case
    }

    return 0;
}
