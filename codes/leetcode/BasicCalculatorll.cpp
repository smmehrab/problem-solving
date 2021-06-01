/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution {
public:
    int calculate(string input) {
        char operation = '+';
        int operand, otherOperand, finalAnswer=0;
        stack<int> answers;
        
        istringstream inputstream(input);
        while(inputstream >> operand){
            if(operation=='+') answers.push(operand);
            else if(operation=='-') answers.push(operand*(-1));
            else{
                otherOperand = answers.top();
                answers.pop();
                if(operation=='*') answers.push(otherOperand*operand);
                else if(operation=='/') answers.push(otherOperand/operand);
            }
            inputstream >> operation;
        }
        
        while(!answers.empty()){
            finalAnswer += answers.top();
            answers.pop();
        }
        return finalAnswer;
    }
};