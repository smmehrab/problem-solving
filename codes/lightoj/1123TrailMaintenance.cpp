#include<bits/stdc++.h>
using namespace std;

int n, w;
vector<pair<int, pair<int, int>>> trails;
vector<pair<int, pair<int, int>>> selectedTrails;
int parent[205];

void init() {
    trails.clear();
    for(int i=0; i<=n; i++)
        parent[i] = i;
}

int findRoot(int x){
    while(parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

int kruskal(){
    int a, b, c, aRoot, bRoot, selected;
    int minLength = 0;
    sort(trails.begin(), trails.end());

    // Kruskal Variation
    selected = 0;
    selectedTrails.clear();
    for(int i=0; i<=n; i++) 
        parent[i] = i;

    for(pair<int, pair<int, int>> trail : trails){
        a = trail.second.first;
        b = trail.second.second;
        c = trail.first;
        aRoot = findRoot(a);
        bRoot = findRoot(b);
        if(aRoot != bRoot){
            minLength += c;
            parent[aRoot] = parent[bRoot];

            // Kruskal Variation
            selected++;
            selectedTrails.push_back(trail);
            if(selected==n-1)
                break;
        }
    }

    // Kruskal Variation
    trails = selectedTrails;
    return (selected==n-1) ? minLength : -1;
}

int main() {
    int testCaseCount;
    int a, b, c;
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cout << "Case " << testCase << ":" << endl;
        init();
        cin >> n >> w;
        for(int i=0; i<w; i++) {
            cin >> a >> b >> c;
            trails.push_back({c, {a, b}});
            cout << kruskal() << endl;
        }
    }
    return 0;
}