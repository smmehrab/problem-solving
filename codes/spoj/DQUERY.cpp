/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
// #include<bits/stdc++.h>
// using namespace std;

// struct Query{
//     int start, end, index;
//     Query(int start, int end, int index) : start(start), end(end), index(index) {};
// };

// int numberOfValues, numberOfQueries, x, y, blockSize, frequencies[200200];
// vector<Query> queries;

// bool compare(const Query& a, const Query& b){
//     return (a.start/200 < b.start/200) || (a.start/200 == b.start/200 && a.end < b.end);
// }

// int main(){
//     memset(frequencies, 0, sizeof(frequencies));

//     cin >> numberOfValues;
//     vector<int> values(numberOfValues, 0);

//     blockSize = sqrt(numberOfValues);
//     for(int i=0; i<numberOfValues; i++) 
//         cin >> values[i];
    
//     cin >> numberOfQueries;
//     vector<int> results(numberOfQueries, 0);
//     for(int i=0; i<numberOfQueries; i++) {
//         cin >> x >> y;
//         queries.push_back(Query(x-1, y-1, i));
//     }

//     sort(queries.begin(), queries.end(), compare);

//     int currentDistinctCount = 0;
//     int start = 0;
//     int end = -1;

//     for(Query query : queries) {
//             while (start < query.start) {
//                 frequencies[values[start]]--;
//                 if (frequencies[values[start]] == 0) 
//                     currentDistinctCount--;
//                 start++;
//             }
//             while (start > query.start) {
//                 start--;
//                 frequencies[values[start]]++;
//                 if (frequencies[values[start]] == 1) 
//                     currentDistinctCount++;
//             }
//             while (end < query.end) {
//                 end++;
//                 frequencies[values[end]]++;
//                 if (frequencies[values[end]] == 1) 
//                     currentDistinctCount++;
//             }
//             while (end > query.end) {
//                 frequencies[values[end]]--;
//                 if (frequencies[values[end]] == 0) 
//                     currentDistinctCount--;
//                 end--;
//             }
            
//             results[query.index] = currentDistinctCount;
//     }

//     for(int result : results) cout << result << endl;
//     return 0;
// }












#include <bits/stdc++.h>
using namespace std;

struct Query {
    int start, end, block, index;
    Query(int start, int end, int block, int index) : start(start), end(end), block(block), index(index) {};
};

bool compare(const Query &a, const Query &b) {
    return (a.block<b.block) ? true : ((a.block>b.block) ? false : (a.end<b.end));
}

int main(){
    int n, q, blockSize;
    int frequencies[1000100];
    memset(frequencies, 0, sizeof(frequencies));

    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
        cin >> values[i];

    blockSize = sqrt(n);

    cin >> q;
    vector<Query> queries;
    vector<int> results(q);
    int x, y;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        queries.push_back(Query(x, y, (x/blockSize), i));
    }

    sort(queries.begin(), queries.end(), compare);

    int start = 0, end = -1, distinctCount = 0;
    for (const Query &query : queries) {
        while (start < query.start) {
            frequencies[values[start]]--;
            distinctCount -= (frequencies[values[start]] == 0);
            start++;
        }
        while (start > query.start) {
            start--;
            frequencies[values[start]]++;
            distinctCount += (frequencies[values[start]] == 1);
        }
        while (end < query.end) {
            end++;
            frequencies[values[end]]++;
            distinctCount += (frequencies[values[end]] == 1);
        }
        while (end > query.end) {
            frequencies[values[end]]--;
            distinctCount -= (frequencies[values[end]] == 0);
            end--;
        }
        results[query.index] = distinctCount;
    }

    for (int result : results)
        cout << result << endl;

    return 0;
}