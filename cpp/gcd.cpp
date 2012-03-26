#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    int Remainder;

    while( b != 0 )
    {
        Remainder = a % b;
        a = b;
        b = Remainder;
    }

    return a;
}

int main()
{
	int x, y;

	cout << "This program allows calculating the GCD\n";
	cout << "Value 1: ";
	cin >> x;
	cout << "Value 2: ";
	cin >> y;

	cout << "\nThe Greatest Common Divisor of "
	     << x << " and " << y << " is " << GCD(x, y) << endl;  

	return 0;
}
