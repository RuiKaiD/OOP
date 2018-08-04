#include "std_lib_facilities.h"
#include "token.h"
#include "vars.h"





const string prompt = ">> ";
const string result = " = ";

double statement();
double expression();
double term();
double expon();
double primary();
void clean_up_mess();
void calculate();

Token_stream ts;

double statement(){
	Token t = ts.get();
	if (t.kind == name){
		Token var = t;
		t = ts.get();
		if (t.kind == '='){
			double d = expression();
			set_value(var.name, d);
			return d;
		}
		else if (t.kind == print){
			ts.putback(t);
			return get_value(var.name);
		}
		ts.putback(t);
		ts.putback(var);
		return expression();
	}
	ts.putback(t);
	return expression();
}

double expression(){
	double left = term();
	Token t = ts.get();

	while (true) {
		switch(t.kind){
			case '+': 
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double term(){
	double left = expon();
	Token t = ts.get();

	while (true){
		switch(t.kind){
			case '*': 
				left *= expon();
				t = ts.get();
				break;
			case '/':{
				double d = expon();
				if (d == 0) error("Divided by zero");
				left /= d;
				t = ts.get();
				break;
			}
			case '%':{
				double d = expon();
				if (d == 0) error("Divdied by zero");
				left = fmod(left, d);
				t = ts.get();
				break;
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}



double primary(){
	Token t = ts.get();
	switch(t.kind){
		case '(':{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return d;
		}
		case number:
			return t.value;
		case name:
			return get_value(t.name);
		case '+':
			return primary();
		case '-':
			return -primary();
		default:
			error("primary expected");
	}
	return 0.0;
}

double expon(){
	double left = primary();
	Token t = ts.get();
	if (t.kind == power){
		double d = primary();
		return pow(left, d);
	}
	else {
		ts.putback(t);
		return left;
	}
}



void clean_up_mess(){
	while (true){
		Token t = ts.get();
		if (t.kind == print) return;
	}
}

void calculate(){
	while (cin) {
		try{

			cout << prompt;
			Token t = ts.get();

			while (t.kind == print) t = ts.get();
			if (t.kind == quit) return;

			ts.putback(t);

			cout << setprecision(12) << result << statement() << endl;
		}
		catch(exception& e){
			cerr << e.what() << endl;
			clean_up_mess();
		}
	}
}


int main(){


	



	try{
		calculate();
		return 0;
	}


	catch(...){
		cerr << "Exception occurred \n";
		return 2;
	}
}