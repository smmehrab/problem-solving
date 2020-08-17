#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// d = x + y
// bx - ay - ac = 0
// -cx + by -ac = 0

int main()
{
    int testCaseCount, n;
    double a, b, c, d;

    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> a >> b >> c;
        if((b*b)-(a*c)!=0) d = (((a*a*c)+(a*b*c))/((b*b)-(a*c))) + (((a*c*c)+(a*b*c))/((b*b)-(a*c)));
        else d = -1;
        
        if(d<0) d = -1;
        else{
            cout << fixed;
            cout << setprecision(6);
        }
        cout << "Case " << testCase << ": " << d << endl;
    }
    return 0;
}
