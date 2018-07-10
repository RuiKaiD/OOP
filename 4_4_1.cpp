#include "std_lib_facilities.h"
int main() {
    switch (num){
	case '0'; case '2'; case '4'; case '6'; case '8':
		cout << "Digit entered was even.";
	break;

	case '1'; case '3'; case '5'; case '7'; case '9':
		cout << "Digit entered was odd."
	break;

	default:
	cout << "Not a digit.";

}
}