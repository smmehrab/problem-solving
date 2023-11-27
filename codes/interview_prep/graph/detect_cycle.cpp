#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, graph[11][11], answer[11], answer_size = -1;
int stack[15], top = -1, visited[11], min_cycle_sum = 999999;

void detect_cycle(int current) {
    if(visited[current] == 1 && top != -1) {
        int i;
        int cycle_sum = stack[top];
        for(i=top-1;i>=0 && stack[i]!=current;i--) {
            cycle_sum += stack[i];
        }
        if(i != -1 && cycle_sum < min_cycle_sum) {
            answer_size = -1;
            min_cycle_sum = cycle_sum;
            answer[++answer_size] = stack[top];
            for(i=top-1;i>=0 && stack[i]!=current;i--) {
                answer[++answer_size] = stack[i];
            }
        }
        return;
    }

    visited[current] = 1;
    for(int i=1;i<=n;i++) {
        if(graph[current][i] == 1) {
            stack[++top] = i;
            detect_cycle(i);
            top--;
        }
    }
    visited[current] = 0;
}

int main() {
    int i, j, t1, t2;
    cin >> n >> m;

    while(m--) {
        cin >> t1 >> t2;
        graph[t1][t2] = 1;
    }

    for(i=1;i<=n;i++) {
        if(visited[i] == 0) {
            stack[++top] = i;
            detect_cycle(i);
            top--;
        }
    }

    sort(answer, answer+answer_size+1);
    for(i=0; i<=answer_size; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}