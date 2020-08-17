#include <bits/stdc++.h>
#include <string>
using namespace std;

bool longDivision(string number, long long int divisor) 
{ 
	string answer; 

    if(number.size()==1 && number[0]=='0'){
        return true;
    }

	long long int position = 0; 
	long long int temp = number[position] - '0'; 
    long long int remainder;

	while (temp < divisor) 
		temp = temp * 10 + (number[++position] - '0'); 

	while (number.size() > position) { 
		answer += (temp / divisor) + '0'; 
        remainder =  (temp % divisor);
		temp = remainder * 10 + (number[++position] - '0'); 
	} 

    if(answer.size()==0){
        return false;
    }
	else if (remainder==0 && answer.size()!=0){
        return true;
    } 
	
	return false; 
} 

int main()
{
    long long int testCaseCount, b;
    string a, answer;
    bool isDivisible;

    cin >> testCaseCount;
    for (long long int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> a >> b;

        if(a[0]=='-'){
            a.erase(a.begin()); 
        }

        if(b<0){
            b*=-1;
        }

        isDivisible = longDivision(a, b);
        
        if(isDivisible){
            answer = "divisible";
        }else{
            answer = "not divisible";
        }

        cout << "Case " << testCase << ": " << answer << endl;
    }
    return 0;
}