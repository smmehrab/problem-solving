#include<bits/stdc++.h>
using namespace std;

#define PRIME_LIMIT 65540
#define MODULO 1000000007

vector<long long int> primes;

void seive() {
    bool isPrime[PRIME_LIMIT];
    memset(isPrime, true, sizeof(isPrime));
    for(int number=2; number<PRIME_LIMIT; number++){
        if(isPrime[number]) {
            primes.push_back(number);
            for(int multiple=2*number; multiple<PRIME_LIMIT; multiple+=number) isPrime[multiple] = false;
        }
    }
}

long long int longPow (long long int base, long long int power) {
    long long int result = 1;
    while (power>0) {
        if (power&1) result = (result * base) % MODULO;     
        base = (base * base) % MODULO;
        power >>= 1;
    }
    return result;
}

long long int sumOfDivisors(long long int base, long long int power) {
    long long int result = (longPow(base, power+1)-1) % MODULO; // a^(n+1) - 1 
    long long int modularMultiplicativeInverse = longPow(base-1, MODULO-2); // a-1
    result = (result * modularMultiplicativeInverse) % MODULO; // s = (a^(n+1)-1)/a-1
    result = (result + MODULO) % MODULO;
    return result; 
}

int main() {
    int testCaseCount;
    long long int n, m, power, answer;

    seive();
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n >> m;
        answer = 1;
        for(int prime : primes){
            if(n%prime==0){
                power = 0;
                while(n%prime==0){
                    power++;
                    n /= prime;
                }
                answer = (answer * sumOfDivisors(prime, power*m)) % MODULO;
            }
        }
        if(n!=1) answer = (answer * sumOfDivisors(n, m)) % MODULO;
        cout << "Case " << testCase << ": " << answer << endl;
    }

    return 0;
}