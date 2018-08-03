#include "std_lib_facilities.h"

int main(){
	char c = 'x';
	int i = 17;
	double d =2.71828;

	char* cp = &c;
	int* ip = &i;
	double* dp = &d;


	cout << "char pointer is " << cp << " and char content is " << *cp << ". "
	 << "Size of char pointer is " << sizeof(cp) << " and the size of char is " << sizeof(c) << '\n';

	cout << "int pointer is " << ip << " and int content is " << *ip << ". "<<
	 "Size of iint pointer is " << sizeof(ip) << " and the size of int is " << sizeof(i) << '\n';

	cout << "double pointer is " << dp << " and double content is " << *dp <<". "
	<< "Size of double pointer is " << sizeof(dp) << " and the size of double is " << sizeof(d) << '\n';
}
/*
char pointer is x and char content is x. Size of char pointer is 8 and the size of char is 1
int pointer is 0x7fff4a02114c and int content is 17. Size of iint pointer is 8 and the size of int is 4
double pointer is 0x7fff4a021150 and double content is 2.71828. Size of double pointer is 8 and the size of double is 8