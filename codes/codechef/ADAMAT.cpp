#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCases, n, x;
    cin >> testCases;
    while(testCases--){
        cin >> n;
        int a[n][n];         
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> a[i][j];
            }
        }

        int ans = 0;
        bool justSwapped = false;
        for(int i=0; i<n; i++){
            if(a[0][i]!=i+1){
            	if(justSwapped){
            		swap(a[0][i], a[i][0]);
            	}
            	else{
	                ans += (i<2) ? 1 : 2;
	                for(int j=0; j<=i; j++) swap(a[0][j], a[j][0]);
	            	justSwapped = true;	
            	}
            }
            else{
            	justSwapped = false;
            }
        }

        cout << ans << endl;
    }
    return 0;
}