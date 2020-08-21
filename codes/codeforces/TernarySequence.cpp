#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, ans, x1, y1, z1, x2, y2, z2;
    cin >> t;
    while(t--){
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;

        ans = 0;

        int d = min(z1, y2);
        ans += 2*d;
        z1 -= d;
        y2 -= d;

        d=min(y1, y2);
        y1 -= d;
        y2 -= d;    

        d=min(y1, x2);
        y1 -= d;
        x2 -= d;

        d=min(x1, x2);
        x1 -= d;
        x2 -= d;     

        d=min(x1, z2);
        x1 -= d;
        z2 -= d;  

        d=min(z1, z2);
        z1 -= d;
        z2 -= d;  

        d=min(x1, y2);
        x1 -= d;
        y2 -= d;  

        d=min(y1, z2);
        ans -= 2*d;
        y1 -= d;
        z2 -= d;  

        cout << ans << endl;
    }

    return 0;
}