#include <bits/stdc++.h>
using namespace std;

// Just Solving 12x2 + 4x(l+w) + lw = 0

int main(){
    int testCaseCount;
    double l, w;
    double a, b, c, x1, x2, x, ans;

    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++){
        cin >> l >> w;

        a = 12.00;
        b = (-4)*(l+w);
        c = l*w;

        x1 = (-b+sqrt((b*b)-(4*a*c)))/(2*a);
        x2 = (-b-sqrt((b*b)-(4*a*c)))/(2*a);

        if(x1>=0 && x1< min(l, w)/2.00) x = x1;
        else x = x2;

        ans = (l-(2*x))*(w-(2*x))*x;
        printf("Case %d: %0.10lf\n", testCase, ans);
    }
    return 0;
}
