#include<bits/stdc++.h>
using namespace std;

#define MODULO 1000000007
#define MAX 100001

long long int factorials[100001];

long long int bigMod(long long int b, long long int p){
    if(p == 0) return 1;
    if(p&1) return ((b % MODULO) * (bigMod(b, p-1))) % MODULO;
    long long c = bigMod(b, p/2);
    return ((c % MODULO) * (c % MODULO)) % MODULO;
}

void precalculateFactorials(){
    factorials[0]=1;
    for(int i = 1; i<=100000; i++) factorials[i]=(i*factorials[i-1])%MODULO;
}

long long int nCr(long long int n, long long int r){
    long long int result = factorials[n];
    long long int tmp = (factorials[r] * factorials[n-r]) % MODULO;
    result = (result * bigMod(tmp, MODULO-2)) % MODULO;
    return result;
}

int main(){
    precalculateFactorials();
    int testCases, n;
    cin >> testCases;
    while(testCases--){
        cin >> n;

        vector<int> cards(n);
        int maximumCard = -1, maximumCardFrequency;

        for(int &card : cards){
            cin >> card;
            if(card>maximumCard){
                maximumCard = card;
                maximumCardFrequency = 1;
            }
            else if(card == maximumCard){
                maximumCardFrequency++;
            }
        }

        long long int possibilities = bigMod(2, n);
        if(maximumCardFrequency%2==0) {
            long long int drawPossibilities = bigMod(2, n-maximumCardFrequency);
            drawPossibilities = (drawPossibilities * nCr(maximumCardFrequency, maximumCardFrequency/2)) % MODULO;
            possibilities = (possibilities-drawPossibilities+MODULO) % MODULO;
        }

        cout << possibilities << endl;
    }

    return 0;
}