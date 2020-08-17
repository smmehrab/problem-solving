#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
using namespace std;

// Driver Code
int main()
{
    int testCaseCount;
    int testCase;
    int n, p, prevP, nextP;
    scanf("%d", &testCaseCount);
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        bool found = false, num1, num2, num3;
        cin >> n;
        int map[n];
        for(int index=0; index<n; index++){
            cin >> p;
            map[p] = index;
        }
        
        for(int index=0; index<n; index++){
            if(map[index]!=0 || map[index]!=n-1){
                if(map[index]> map[index-1] && map[index]>map[index+1]){
                    found=true;
                    num1 = index;
                    num2 = index-1;
                    num3 = index+1;
                }
            }
        }

        if(found){
            cout << "YES" << endl;
            cout << num1 << " " << num2 << " " << num3 << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}