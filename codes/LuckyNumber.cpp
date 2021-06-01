/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

int main(){

    int numberOfQueries;
    int query;
    int result;


    cin >> numberOfQueries;

    for(int queryIndex=1;queryIndex<=numberOfQueries; queryIndex++){
        result = 1;
        cin >> query;

        if(query!=1){
            if(query%2==0){
                result = ((query-2)*6)+3;
            } else{
                result = ((query-1)*6)+1;
            }
        }

        cout << "Case " << queryIndex << ": " << result << endl;
    }

    return 0;
}







