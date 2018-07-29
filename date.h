#include "std_lib_facilities.h"
//struct Date{
//	int y;
//	int m;
//	int
//};

enum class Month{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};


Month operator++(Month&m);

class Date{
public:

	class Invalid{};

	Date(int y, Month m, int d);
	Date();

	
	Month month() const {return m;}
	int year() const {return y;}
	int day() const {return d;}

	void add_year(int n);
	void add_month(int n);
	void add_day(int n);

private:
	int y , d;
	Month m;
	bool is_valid();
	bool is_leapyear();
};

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

ostream& operator<<(ostream& os, const Date& date);
istream& operator>>(istream& is, Date& date);