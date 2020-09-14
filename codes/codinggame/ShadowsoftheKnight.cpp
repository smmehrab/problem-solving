#include <bits/stdc++.h>
using namespace std;

int main(){
    int width, height, maximumJumps;
    int xLeft, xRight, yUp, yDown, x, y;
     
    cin >> width >> height;
    cin >> maximumJumps; 
    cin >> x >> y; 

    xLeft = 0;
    xRight = width-1;
    yUp = 0;
    yDown = height-1;

    while (true) {
        string direction; 
        cin >> direction;

        if (direction == "L") xRight = x-1;
        else if (direction == "R") xLeft = x+1;
        else if (direction == "U") yDown = y-1;
        else if (direction == "D") yUp = y+1;
        
        if (direction == "UL" || direction == "DL") xRight = x-1;
        else if (direction == "UR" || direction == "DR") xLeft = x+1;
        if (direction == "UL" || direction == "UR") yDown = y-1;
        else if (direction == "DL" || direction == "DR") yUp = y+1; 

        x=xLeft+(xRight-xLeft)/2;  
        y=yDown+(yUp-yDown)/2;  
        cout << x << " " << y << endl;
    }
}