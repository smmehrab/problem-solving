#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    char s[n];
    cin >> s;

    int r=0,v=0;

    for(int i=0;s[i];i++){
        if(s[i]=='U' && r==-1){
            v++;
            r++;
        }
        else if(s[i]=='U') r++;
        else if(s[i]=='D') r--;
    }

    cout << v << endl;

}
