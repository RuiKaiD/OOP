#include "std_lib_facilities.h"


const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = " > ";
const string result = " = ";



class Token{
	public:
		char kind;
		double value;
};

class Token_stream{

	public:
		Token get();
		void putback(Token t);
		void ignore(char c);

	private:
		Token buffer;
		bool full{false};	
};

void Token_stream::putback (Token t){
	buffer = t;
	full = true;
}

Token Token_stream::get(){
	if(full){
		full=false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch(ch){
		case print:
		case quit:
		case'(':
		case')':
		case'+':
		case'-':
		case'/':
		case'*':
		case'%':
			return Token{ch};

		case'.':
		case'0':case'1':case'2':case'3':case'4':
		case'5':case'6':case'7':case'8':case'9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token{number,val};
		}
		default:
			return Token{'i',double(ch)};
	}
	return Token{quit};
}

//Token_stream ts;
//Token;
//Token_Stream;
//Token_Stream::putback();
//Token_Stream::get();

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind){
		full = false;
		return;
	}

	full= false;

	char ch = 0;
	while(cin >> ch)
		if(ch == c) return;
}

Token_stream ts;

void clean_up_mess()
{
	ts.ignore(print);
}

//function declaration:

double expression();
double primary();
double term();

double expression(){

	double left = term();
	Token t = ts.get();
	
	while(true){
		switch(t.kind){
			case'+':
				left += term();
				t = ts.get();
				break;
			case'-':
				left -= term();
				t = ts.get();
				break;
			default:
			    ts.putback(t);
				return left;

		}
	}

}

double primary(){
	Token t=ts.get();


	switch(t.kind){
		case'(':{
			double d = expression();
			t=ts.get();
			if (t.kind != ')') error ("')' expected");
			return d;

		}
		case number:

			return t.value;
		case'-':
			return -primary();

		case'+':
			return primary();

		default:
			//string s = "expected primary but got ";
			//s.push_back(t.kind);
			//error(s);
			error("primary expected");
	}
	
}

double term(){
	double left = primary();
	
	
	Token t =ts.get();

	while (true){
		switch (t.kind){
			case'*':
			left *= primary();
			t=ts.get();
			break;

			case'/':
			{
				double d = primary();
				if (d == 0) error("divide by zero");
				left /= d;
				t=ts.get();
				break;
			}
			case'%':
			{
				double d = primary();
				if (d == 0) error ("divide by zero");

				left = fmod(left,d);

				t=ts.get();
				break;
			}

			default:
			ts.putback(t);
			return left;
		}
	}

}


	
	void calculate(Token_stream& ts)
	{
		while(cin){
			try{
				cout << prompt;
				Token t=ts.get();

				//cout << "in calculate(), got token: " 
				//	<< t.kind << " with value of " << t.value <<'\n';

				while(t.kind == print) t=ts.get();
				if(t.kind == quit) return;
				ts.putback(t);
				double d;
				d = expression();
				//cout << "Expression evaluates to " << d << endl;
				cout<< result << d << '\n';
			}
			catch(exception& e){
				cerr << e.what() << '\n';
				clean_up_mess();
			}
		}
	}


int main(){
	
	try {
		calculate(ts);
		return 0;
	}
	catch(...){
		cerr << "unknown exception \n";
		return 2;
	}

	}
	



