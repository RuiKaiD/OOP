//#include "std_lib_facilities.h"
#include "date.h"
//#include "date.cpp"

int main(){
	cout<<"Please enter a date in format (YYYY,MM,DD): \n";
	Date date;
	cin>>date;

	cout<< "The date you enter is: "<< date<<"\n";

	cout<<"Please enter numbers of years to add to the date:\n";
	int y;
	cin>>y;
	date.add_year(y);
	cout <<"After adding "<<y<<" years ,the date is : "<< date<<"\n";

	cout<<"Please enter numbers of months to add to the date:\n";
	int m;
	cin>>m;
	date.add_month(m);
	cout <<"After adding "<<m<<" months ,the date is : "<< date<<"\n";

	cout<<"Please enter numbers of days to add to the date:\n";
	int d;
	cin>>d;
	date.add_day(d);
	cout <<"After adding "<<d<<" days ,the date is : "<< date<<"\n";

	return 0;
}

