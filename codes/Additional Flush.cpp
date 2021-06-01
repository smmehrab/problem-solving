/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
// C++ program to demonstrate the
// use of flush function
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
int main()
{
   for (int i = 1; i <= 5; ++i)
   {
      cout << i << " " << flush;
      this_thread::sleep_for(chrono::seconds(1));
   }
   return 0;
}
