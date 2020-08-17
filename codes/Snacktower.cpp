#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[100011],i,max;
    memset(a,0,sizeof(a));

    cin >> n;
    max=n;

    while(n--){
        cin >> i;
        a[i]=1;
        while(max&&a[max])
            cout << max-- << " ";
        cout << endl;
    }

    return 0;
}
