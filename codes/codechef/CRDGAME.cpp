/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;

long long int powerOf(long long int cardValue) {
    long long int power = 0, digit;
    while (cardValue > 0) {
        digit = cardValue % 10;
        cardValue /= 10;
        power += digit;
    }

    return power;
}

int main() {
    long long int testCases, numberOfRounds, chefCardValue, mortyCardValue, chefCardPower, mortyCardPower, chefPoints, mortyPoints;
    cin >> testCases;
    while (testCases--) {
        cin >> numberOfRounds;

        chefPoints = 0;
        mortyPoints = 0;
        for (int round=0; round<numberOfRounds; round++) {
            cin >> chefCardValue >> mortyCardValue;
            chefCardPower = powerOf(chefCardValue);
            mortyCardPower = powerOf(mortyCardValue);

            if (chefCardPower >= mortyCardPower) chefPoints++;
            if (chefCardPower <= mortyCardPower) mortyPoints++;
        }

        if (chefPoints > mortyPoints) cout << "0 " << chefPoints << endl;
        else if (chefPoints < mortyPoints) cout << "1 " << mortyPoints << endl;
        else cout << "2 " << chefPoints << endl;
    }
    
    return 0;
}