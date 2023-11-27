// #include <iostream>
// #include <climits>
// using namespace std;

// int n;
// int gate[3];
// int people[3];
// int sum;

// int ans=INT_MAX;

// int abs(int a){
//     return a>=0?a:-a;
// }

// void solve(int index, int val, int count){
//     if(count==sum){
//         ans=min(ans, val);
//         return;
//     }
//     if(index==n+1){
//         return;
//     }

//     for(int i=0;i<3;i++){
//         if(people[i]>0){
//             people[i]--;
//             solve(index+1, val+abs(gate[i]-index)+1, count+1);
//             people[i]++;
//         }
//     }
//     solve(index+1, val, count);
// }

// int main(){
//     cin>>n;
//     for(int i=0;i<3;i++){
//         cin>>gate[i];
//     }
//     for(int i=0;i<3;i++){
//         cin>>people[i];
//         sum+=people[i];
//     }
    
//     solve(1, 0, 0);
//     cout<<ans<<endl;
//     return 0;
// }
#include<iostream>
using namespace std;

int n, a[20], gp1, gp2, gp3, nf1, nf2, nf3, c_m;
int max(int a, int b) {
    if(a>b)
        return a;
    return b;
}
void solve() {
    for(int i=1;i<=n-nf2-nf3;i++) {
        for(int j=i+nf1;j<=n-nf3;j++) {
            for(int k=j+nf2;k<=n;k++) {
                int c = 0;
                for(int p=i;p<i+nf1;p++)
                    c += abs(gp1-p);
                for(int p=j;p<j+nf2;p++)
                    c += abs(gp2-p);
                for(int p=k;p<k+nf3;p++)
                    c += abs(gp3-p);
                c += nf1 + nf2 + nf3;
                c_m = min(c_m, c);
            }
        }
    }
}
int main() {
        cin>>n;
        for(int i=0;i<20;i++) a[i] = 0;
        cin>>gp1>>gp2>>gp3;
        cin>>nf1>>nf2>>nf3;
        c_m = 99999;
        solve();    
        cout<<c_m<<endl;
    return 0; 
} 