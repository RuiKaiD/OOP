#include "std_lib_facilities.h"
int main() {
	double a = 3.6; // convert double to int
	int b = a;
	double c =b;
	cout << a;   // initial value is 3.6
	cout <<' ';
	cout << c;   //  c equals 3, is not 3.6
	cout <<' ';

	double e = 3.6; // convert double to char
	char f = e;
	double g = f;
	cout << e;
	cout <<' ';
	cout << g;
	cout <<' '; // initial value is 3.6, g equals to 3

	double h = 3.6; // convert double to bool
	bool i = h;
	double j = i;
	cout << h;
	cout <<' ';
	cout << j;
	cout <<' '; // initial value is 3.6, j equals to 1

	int k = 100000;  // convert int to char
	char l = k;
	int m = l;
	cout << k;
	cout <<' ';
	cout << m;
	cout <<' ';  // initial value is 100000, m equals to -96

	int n = 100000;  // convert int to char
	char o = n;
	int p = o;
	cout << n;
	cout <<' ';
	cout << p;
	cout <<' ';    // initial value is 100000, p equals to -96

	char q = 'z'; // convert char to bool
	bool r = q;
	char s = r;
	cout << q;
	cout <<' ';
	cout << s;
	cout <<' '; // initial value is 'z', s equals to ' '


}