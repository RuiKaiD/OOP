#include "std_lib_facilities.h"

struct Reading{
	int hr;
	char comma1;
	double temp1;
	char comma2;
	double temp2;

};



int main(){

	string iname;
	cout << "please enter the name of input file: \n";
	cin >> iname;
	ifstream ist{iname};

	if (!ist) error("can't open the input file ", iname);

	string oname;
	cout << "\nPlease enter the name of the output file: \n";
	cin >> oname;
	
	ofstream ost{oname};

	if (!ost) error("can't open the output file ", oname);

	vector<Reading> temps;

	int hr;
	char comma1, comma2;
	double temp1, temp2;



	while (ist >> hr >> comma1 >>temp1 >> comma2 >> temp2)
	{
		if (hr < 0 || hr > 23) 
			error("Hour out of range");

		temps.push_back(Reading{hr, comma1, temp1, comma2, temp2});
	}


	for (int i = 0;i < temps.size();++i){

		ost << temps[i].hr << '\t' 
				<< temps[i].temp1 << '\t' << 
				temps[i].temp2 << endl;
			}
}