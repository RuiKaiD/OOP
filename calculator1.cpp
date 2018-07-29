#include "std_lib_facilities.h"
int main (){
	cout << "Please enter expression:\n";
	int lval;
	int rval;
	char op;
	int res;
	cin >> lval>> op >> rval;
	if (op == '+'){
		res = lval + rval;
	}
	if (op == '-'){
		res = lval - rval;
	}
	cout << res << '\n';

}