//
//  main.cpp
//  DateOverWriteOperands
//
//  Created by Caden Finley on 9/21/23.
//
#include <sstream>
#include <iostream>
#include "date.h"
using namespace std;
int main()
{
    Date x, y;

    cout << "Enter x: ";
    cin >> x;
    
    cout << "Enter y: ";
    cin >> y;
    
    if( x < y )
        cout << x << " is earlier.\n";
    else if( x == y )
        cout << "The two dates are the same.\n";
    else
        cout << y << " is earlier.\n";
    
    cout << "A week after " << x << " would be " << x+7 << endl;
    
    cout << "The day after " << y << " would be " << y+1 << endl;
    
    cout << "Ten days:\n";
    for( int i = 0; i < 10; i++ )
    {
        cout << y << endl;
        y.nextDay(); // change y to next day, same as "y = y + 1"
    }
}
