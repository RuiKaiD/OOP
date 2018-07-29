//#include "std_lib_facilities.h"
#include "date.h"

Date::Date(int yy, Month mm, int dd)
:y{yy}, m{mm},d{dd}
{
	if (!is_valid()) throw Invalid{};
}

const Date& def_date()
{
	static const Date d(1996, Month::jan,1);
	return d;
}

Date::Date()
:y{def_date().year()},m{def_date().month()},d{def_date().day()}
{
}

void Date::add_year(int n){
		y+=n;
		if(!is_valid()){
			m=Month(int(3));
			d=1;
		}

}

void Date::add_month(int n){
	for(int i =1;i<=n;i++){
		if(int(m)==12){
			y+=1;
			m=Month(int(1));
		}
		else{m=Month(int(m)+1);}
	}

	if(!is_valid()){
		m=Month(int(m)+1);
		d=1;
	}

}

void Date::add_day(int n){
	for(int i=1;i<=n;i++){
		switch(int(m)){
			case 4:
			case 6:
			case 9:
			case 11:
			{
				if(d==30){
					d=1;
					m=Month(int(m)+1);
				
				}
				else {d+=1;
				}
			break;	
			}

			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			{
				if(d==31){
					
					d=1;
					m=Month(int(m)+1);
				
				}
				else{
					
					d+=1;
					}
			break;
			}

			case 2:{
				if (is_leapyear()){

					if(d==29){
						
						d=1;
						m=Month(int(m)+1);
						
					}
					else{
						
						d+=1;

						}
					
				}



				else{
					if(d==28){
						
						d=1;
						m=Month(int(m)+1);
						
					}
					else{
						
						d+=1;
					}

				}
			break;
			}

			case 12:{
				if(d==31){
					d=1;
					m=Month(int(1));
					y+=1;
						
				}
				else{d+=1;
					
				}
			break;
			}

		}
		
	}
}

bool Date::is_leapyear(){

	return (y%4 ==0 && y%100!=0) || y%400 == 0;
}


bool Date::is_valid(){


		switch(int(m)){
			case 4:
			case 6:
			case 9:
			case 11:
			{
				if(d > 30 || d <1) return false;
				else {return true;}
				break;
			}

			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
			{
				if(d > 31 || d<1) return false;
				else{return true;}
				break;

			}
			case 2:
				if (is_leapyear()){

					if(d>29 || d<1) return false;
					else{return true;}
			}
				else{
					if(d>28 || d<1) return false;
					else{return true;}

				}
				break;
		}
	}





bool operator==(const Date& a, const Date& b)
    {
        return a.year()==b.year()&& a.month()==b.month()&& a.day()==b.day();
    }

bool operator!=(const Date& a,const Date& b)
    {
        return !(a==b);
    }


ostream& operator<<(ostream& os, const Date& date){
	vector<string> month_nm{"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", 
                        "Aug", "Sep", "Oct", "Nov", "Dec"};

	return os <<'"'
			<<month_nm[int(date.month())]
			<<' '<<date.day()<<", "
			<<date.year()<<'"';


}



istream& operator>>(istream& is, Date& date){
	int y,m,d;
	char c1,c2,c3,c4;
	is >> c1>>y>>c2>>m>>c3>>d>>c4;
	if(!is) return is;
	if (c1!='('||c2!=','||c3!=','||c4!=')'){
		is.clear(ios_base::failbit);

		return is;
	}
	date = Date(y,Month(m),d);
	return is;

}

Month operator++(Month& m){
	m= (int(m) == 12) ? Month(int(1)) : Month(int(m)+1);
	return m;
}

/*

Month Date::month(){

	return m;
}

int Date::year(){
	return y;
}

int Date::day(){
	return d;
}

*/


