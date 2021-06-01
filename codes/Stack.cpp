/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <iostream>
using namespace std;
int top = -1; //globally defining the value of top ,as the stack is empty .

void push (int stack[ ] , int x , int n)
{
    if ( top == n-1 )          //if top position is the last of position of stack, means stack is full .
    {
        cout << “Stack is full.Overflow condition!” ;
    }
    else
    {
        top = top +1 ;            //incrementing top position
        stack[ top ] = x ;       //inserting element on incremented position .
    }
}
bool isEmpty ( )
{
    if ( top == -1 )  //stack is empty .
        return true ;
    else
        return false;
}
void pop (int stack[ ] ,int n )
{

    if( isEmpty ( ) )
    {
        cout << “Stack is empty . Underflow condition! ” << endl ;
    }
    else
    {
         top = top - 1 ; //decrementing top’s position will detach last element from stack .
    }
}
int size ( )
{
    return top + 1;
}
int topElement ( )
{
    return stack[ top ];
}
// Now lets implementing these functions on the above stack

int main( )
{
    int stack[ 3 ];
    // pushing element 5 in the stack .
    push(stack , 5 , 3 ) ;

    cout << “Current size of stack is ” << size ( ) << endl ;

    push(stack , 10 , 3);
    push (stack , 24 , 3) ;

    cout << “Current size of stack is ” << size( ) << endl ;

    //As now the stack is full ,further pushing  will show overflow condition .
    push(stack , 12 , 3) ;

    //Accessing the top element .
    cout << ”The current top element in stack is “ << topElement( ) << endl;

    //now removing all the elements from stack .
    for(int i = 0 ; i < 3;i++ )
        pop( );
    cout << “Current size of stack is ” << size( ) << endl ;

    //as stack is empty , now further popping will show underflow condition .
    pop ( );

}
