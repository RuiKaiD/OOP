#include "std_lib_facilities.h"
int main (){
	cout << "Please enter expression:\n";
	double lval;
	double rval;
	char op;
	double res;

	cin >> lval;
	if (! cin){
		error (" no left value");
	}

	for (char op; cin >> op;){
		if (op != 'x'){
			cin >> rval;
			if (! cin){
				error ("no right value");
			}
			else{
				switch (op){
					case'+':
					lval = lval + rval;
					break;

					case'-':
					lval = lval - rval;
					break;

					case'*':
					lval = lval * rval;
					break;

					case'/':
					lval = lval / rval;
					break;

					default:
		            cout << lval;
		            return 0;


		}

				}

			}
		}
}